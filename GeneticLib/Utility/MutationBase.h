//--------------------------------------------------
// Utility: Adds `mutations` to candidate solutions
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
	class MutationBase
	{
		public:
			MutationBase() {}
			virtual void Mutate(CandidateBase * candidate) = 0;
	};
}
