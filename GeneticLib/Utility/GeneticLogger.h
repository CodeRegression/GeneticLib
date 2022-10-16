//--------------------------------------------------
// Utility: Defines a basic logger for tracking the genetic algorithm
//
// @author: Wild Boar
//
// @date: 2022-02-07
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/StringUtils.h>

namespace NVL_AI
{
	class GeneticLogger
	{
    public:
    
        /**
         * @brief Log the process starting 
         */
        virtual void Start() 
        {
            cout << "[" << NVLib::StringUtils::GetDateTimeString() << "] " << "Starting Genetic Runner" << endl;
        }

        /**
         * @brief Log the process stopping 
         */
        virtual void Stop() 
        {
            cout << "[" << NVLib::StringUtils::GetDateTimeString() << "] " << "Genetic Runner Stopped" << endl;
        }

        /**
         * @brief Log process messages passed 
         * @param message The message
         */
        virtual void Message(const string& message) 
        {
            cout << "[" << NVLib::StringUtils::GetDateTimeString() << "] " << message << endl;
        }

        /**
         * @brief Show the best result 
         * @param result The best result that we are showing
         */
        virtual void ShowResult(const string& result) 
        {
            cout << "[" << NVLib::StringUtils::GetDateTimeString() << "] RESULT: " << result << endl;
        }

        /**
         * @brief Log that an error has been raised 
         * @param message The error message
         */
        virtual void RaiseError(const string& message) 
        {
            cout << "[" << NVLib::StringUtils::GetDateTimeString() << "] ERROR: " << message << endl;
        }

        /**
         * @brief Log a score update 
         * @param epoch The current epoch
         * @param score The current score
         */
        virtual void UpdateScore(int epoch, double score) 
        {
            cout << "[" << NVLib::StringUtils::GetDateTimeString() << "] Best Score: " << score << " (epoch: " << epoch << ")" <<  endl;
        }

	};
}
