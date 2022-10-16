//--------------------------------------------------
// Implementation of class CandidateFactoryBase
//
// @author: Wild Boar
//
// @date: 2022-02-07
//--------------------------------------------------

#include "CandidateFactoryBase.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param scoreFinder The score finder to use when generating candidate solution scores
 * @param mutator Add a tool for mutating the given solution
 */
CandidateFactoryBase::CandidateFactoryBase(ScoreFinderBase * scoreFinder, MutationBase * mutator) : _scoreFinder(scoreFinder), _mutator(mutator)
{
	// Additional Initialization can go here
}

/**
 * @brief Main Terminator
 */
CandidateFactoryBase::~CandidateFactoryBase()
{
	if (_scoreFinder != nullptr) delete _scoreFinder; 
	if (_mutator != nullptr) delete _mutator;
}

//--------------------------------------------------
// Population Generation
//--------------------------------------------------

/**
 * @brief Generate a random candidate solution
 * @param The id of the candidate that we are generating
 * @return CandidateBase* The solution that has been created
 */
CandidateBase * CandidateFactoryBase::Random(int id) 
{
	auto candidate = PerformRandomGeneration(id);
	auto score = _scoreFinder->GetScore(candidate);
	candidate->SetScore(score);
	return candidate;
}

//--------------------------------------------------
// Population Update
//--------------------------------------------------

/**
 * @brief Generate a candidate solution based on "genetic breeding"
 * @param id The id of the candidate that we are generating
 * @param parent1 The first parent process
 * @param parent2 The second parent process
 * @return CandidateBase* The resultant "child" candidate solution
 */
CandidateBase * CandidateFactoryBase::Breed(int id, CandidateBase * parent1, CandidateBase * parent2) 
{
	auto candidate = PerformBreedGeneration(id, parent1, parent2);
	_mutator->Mutate(candidate);
	auto score = _scoreFinder->GetScore(candidate); candidate->SetScore(score);
	return candidate;
}