//--------------------------------------------------
// Implementation of class GeneticRunner
//
// @author: Wild Boar
//
// @date: 2022-02-11
//--------------------------------------------------

#include "GeneticRunner.h"
using namespace NVL_AI;

/**
 * @brief Main constructor
 * @param factory The factory for spawning new candidates
 * @param populationSize The size of the population we want to use
 * @param sampleSize The sample size for the K-Tournament selection
 */
GeneticRunner::GeneticRunner(CandidateFactoryBase * factory, int populationSize, int sampleSize) : _factory(factory)
{
	InitializePopulation(_population, populationSize);
	_selector = new CandidateSelector(sampleSize);
	_logger = nullptr;
}

/**
 * @brief Main terminator logic
 */
GeneticRunner::~GeneticRunner() 
{
	FreePopulation(_population); 
	// delete _factory; 
	delete _selector;
	if (_logger != nullptr) delete _logger;
}

//--------------------------------------------------
// Execution Logic
//--------------------------------------------------

/**
 * @brief Spawns the process
 * @param iterationMax The maximum number of iterations to perform
 * @return int The number of iterations performed
 */
int GeneticRunner::Run(int iterationMax)
{
	if (_logger != nullptr) _logger->Start();

	int iterations = 0;
	for (auto i = 0; i < iterationMax; i++) 
	{
		if (_logger != nullptr) _logger->Message(NVLib::Formatter() << "Processing generation: " << (i + 1));

		if (_logger != nullptr) _logger->Message("Creating next generation");		
		GetNextPopulation(_population);
		if (_logger != nullptr) _logger->Message("Population complete");		

		_bestScore = _population[0]->GetScore();
		if (_logger != nullptr) _logger->UpdateScore(i, _bestScore);
		if (_logger != nullptr) _logger->ShowResult(_population[0]->ToString());
		
		if (_factory->GetScoreFinder()->ProblemSolved(_population[0])) 
		{
			if (_logger != nullptr) _logger->Message("The strongest member appears to be an optimal solution, quitting now!");
			break;
		}

		iterations++;
	}

	if (_logger != nullptr) _logger->Stop();

	return iterations;
}

//--------------------------------------------------
// Find Best Candidate
//--------------------------------------------------

/**
 * @brief Define the logic to find the best candidate
 * @return CandidateBase* The best candidate that the system found
 */
CandidateBase * GeneticRunner::FindBestCandidate() 
{
	auto winner = FindWinner(_population);
	auto result = winner->Clone();
	winner->SetScore(0);
	return result;
}

//--------------------------------------------------
// Initialize the population
//--------------------------------------------------

/**
 * @brief Initialize the initial population
 * @param population The population that we are initializing	
 * @param populationSize The size that we want the population to be
 */
void GeneticRunner::InitializePopulation(vector<CandidateBase *>& population, int populationSize) 
{
	population.size();
	for (auto i = 0;  i < populationSize; i++) 
	{
		auto candidate = _factory->Random(i);
		population.push_back(candidate);
	}
}

//--------------------------------------------------
// Free Population
//--------------------------------------------------

/**
 * @brief Free the memory associated with the given population
 * @param population The population that we are freeing
 */
void GeneticRunner::FreePopulation(vector<CandidateBase*>& population) 
{
	for (auto& member : population) delete member;
	population.clear(); 
}

//--------------------------------------------------
// Generate Population
//--------------------------------------------------

/**
 * @brief Creates the next population in the system
 * @param previousPopulation The previous population that we are building from
 */
void GeneticRunner::GetNextPopulation(vector<CandidateBase *>& previousPopulation)
{
	// Create a container for the new population
	auto population = vector<CandidateBase *>();

	// Add the Winner - aka elitism
	for (auto i = 0; i < 100; i++) 
	{
		auto winner = FindBestCandidate(); population.push_back(winner);
	}
	
	// Do some breeding to get the result
	auto id = 0;
	while (population.size() < previousPopulation.size()) 
	{
		if (population.size() < 100) 
		{
			auto child = _factory->Random(id++);
			population.push_back(child);
			continue;
		}

		auto parent1 = _selector->Select(previousPopulation);
		auto parent2 = _selector->Select(previousPopulation);

		// make sure that we have different parents!
		while (parent1 == parent2) parent2 = _selector->Select(previousPopulation);

		auto child = _factory->Breed(id++, parent1, parent2);

		population.push_back(child);
	}

	// Free the previous generation
	FreePopulation(previousPopulation);

	// Move the new population across
	for (auto& candidate : population) previousPopulation.push_back(candidate);
}

//--------------------------------------------------
// Find Winner
//--------------------------------------------------

/**
 * @brief Find the winner from the provided population
 * @param population The population we are searching
 * @return CandidateBase * Returns a CandidateBase *
 */
CandidateBase * GeneticRunner::FindWinner(vector<CandidateBase *>& population)
{
	auto bestScore = population[0]->GetScore(); auto bestCandidate = population[0];

	for (auto& candidate : population) 
	{
		if (candidate->GetScore() > bestScore) 
		{
			bestScore = candidate->GetScore(); bestCandidate = candidate;
		}
	}

	return bestCandidate;
}
