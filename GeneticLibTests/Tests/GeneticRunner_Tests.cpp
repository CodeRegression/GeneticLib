//--------------------------------------------------
// Unit Tests for class GeneticRunner
//
// @author: Wild Boar
//
// @date: 2022-02-11
//--------------------------------------------------

#include <gtest/gtest.h>

#include <GeneticLib/Utility/GeneticRunner.h>
using namespace NVL_AI;

#include "../Helpers/Mutation.h"
#include "../Helpers/Candidate.h"
#include "../Helpers/ScoreFinder.h"
#include "../Helpers/CandidateFactory.h"

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Tests the algorithm on a simple problem to confirm that it works
 */
TEST(GeneticRunner_Test, operational_test)
{
	// Setup: Setup the process
	auto solution = vector<bool> { true, false, true, false, true, true, true, false, true, false, true, false, false, true, false, true, false, false, false, true, true, false, true };
	auto tester = new ScoreFinder(solution); auto mutator = new Mutation();
	auto factory = new CandidateFactory(tester, mutator);

	cout << "Solution: ";
	for (auto i = 0; i < solution.size(); i++) 
	{
		if (i != 0) cout << " ";
		cout << solution[i] ? "1" : "0";
	}
	cout << endl;

	auto runner = GeneticRunner(factory, 100, 10);
	runner.SetLogger(new GeneticLogger());

	// Execute
	auto iterations = runner.Run(10);
	auto bestSolution = runner.FindBestCandidate();

	// Confirm
	auto workingSolution = (Candidate *) bestSolution;
	ASSERT_EQ(solution.size(), workingSolution->GetData().size());

	for (auto i = 0; i < solution.size(); i++) 
	{
		ASSERT_EQ(solution[i], workingSolution->GetData()[i]);
	}

	// Teardown
	delete bestSolution;
}
