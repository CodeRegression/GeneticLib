//--------------------------------------------------
// Model: CandidateBase solution to the problem we are trying to find an answer for
//
// @author: Wild Boar
//
// @date: 2022-02-07
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

namespace NVL_AI
{
	class CandidateBase
	{
	private:
		int _id;
		double _score;
	public:
		CandidateBase(int id, double score) : _id(id), _score(score) {}

		virtual string ToString() = 0;
		virtual CandidateBase * Clone() = 0;
		virtual bool Equals(CandidateBase * candidate) = 0;

		inline int GetId() { return _id; }
		inline double GetScore() { return _score; }
		inline void SetScore(double value) { _score = value; }
	};
}
