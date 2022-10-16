//--------------------------------------------------
// Implementation of class CandidateSelector
//
// @author: Wild Boar
//
// @date: 2022-02-10
//--------------------------------------------------

#include "CandidateSelector.h"
using namespace NVL_AI;

//--------------------------------------------------
// Selection
//--------------------------------------------------

/**
 * @brief Select a candidate from a population with a bias towards a great score
 * @param population The population that we are sampling from
 * @return CandidateBase * Returns a CandidateBase *
 */
CandidateBase * CandidateSelector::Select(vector<CandidateBase *>& population)
{
	auto samplePopulation = vector<CandidateBase *>();
	sample(population.begin(), population.end(), back_inserter(samplePopulation), _poolSize, std::mt19937{std::random_device{}()});
	auto it = max_element(samplePopulation.begin(), samplePopulation.end(), CandidateSelector::CompareCandidate);		
	return *it;
}
