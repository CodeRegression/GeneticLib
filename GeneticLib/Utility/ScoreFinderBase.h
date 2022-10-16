//--------------------------------------------------
// Utility: Evaluates a Candidate solutions and gives it a suitability score
//
// @author: Wild Boar
//
// @date: 2022-02-07
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include "../Model/CandidateBase.h"

namespace NVL_AI
{
	class ScoreFinderBase
	{
	public:
		ScoreFinderBase() {}
		virtual double GetScore(CandidateBase * candidate) = 0;
		virtual bool ProblemSolved(CandidateBase * candidate) = 0;
	};
}
