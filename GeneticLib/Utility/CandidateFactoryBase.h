//--------------------------------------------------
// Utility: A factory type utility for generating new candidates
//
// @author: Wild Boar
//
// @date: 2022-02-07
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include "MutationBase.h"
#include "ScoreFinderBase.h"
#include "../Model/CandidateBase.h"

namespace NVL_AI
{
	class CandidateFactoryBase
	{
	private:
		ScoreFinderBase * _scoreFinder;
		MutationBase * _mutator;
	public:
		CandidateFactoryBase(ScoreFinderBase * scoreFinder, MutationBase * mutator);
		~CandidateFactoryBase();

		CandidateBase * Random(int id);
		CandidateBase * Breed(int id, CandidateBase * parent1, CandidateBase * parent2);

		inline ScoreFinderBase * GetScoreFinder() { return _scoreFinder; }
	protected:
		virtual CandidateBase * PerformRandomGeneration(int id) = 0;
		virtual CandidateBase * PerformBreedGeneration(int id, CandidateBase * parent1, CandidateBase * parent2) = 0;
	};
}
