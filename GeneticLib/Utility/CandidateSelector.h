//--------------------------------------------------
// Utility: Use K-Tournament to select Candidates with a bias towards a greater score
//
// @author: Wild Boar
//
// @date: 2022-02-10
//--------------------------------------------------

#pragma once

#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

#include "../Model/CandidateBase.h"

namespace NVL_AI
{
	class CandidateSelector
	{
	private:
		int _poolSize;
	public:
		CandidateSelector(int poolSize) : _poolSize(poolSize) {}

		CandidateBase * Select(vector<CandidateBase *>& population);
	private:
		static bool CompareCandidate(CandidateBase * candidate_1, CandidateBase * candidate_2) 
		{
			return candidate_1->GetScore() < candidate_2->GetScore();
		}
	};
}
