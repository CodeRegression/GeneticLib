//--------------------------------------------------
// Utility: A runner utility for the application
//
// @author: Wild Boar
//
// @date: 2022-02-11
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/Formatter.h>

#include "CandidateFactoryBase.h"
#include "CandidateSelector.h"
#include "GeneticLogger.h"

namespace NVL_AI
{
	class GeneticRunner
	{
	private:
		CandidateFactoryBase * _factory;
		vector<CandidateBase *> _population;
		CandidateSelector * _selector;
		GeneticLogger * _logger;
		double _bestScore;
	public:
		GeneticRunner(CandidateFactoryBase * factory, int populationSize, int sampleSize); 
		~GeneticRunner(); 

		int Run(int iterationMax);

		CandidateBase * FindBestCandidate();

		inline void SetLogger(GeneticLogger * logger) { _logger = logger; }
		inline double GetBestScore() { return _bestScore; }

	private:
		void InitializePopulation(vector<CandidateBase *>& population, int populationSize);
		void FreePopulation(vector<CandidateBase*>& population);
		void GetNextPopulation(vector<CandidateBase *>& previousPopulation);
		CandidateBase * FindWinner(vector<CandidateBase *>& population);
	};
}
