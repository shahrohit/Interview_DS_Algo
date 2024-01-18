#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Gas Station
 * Leetcode No : 134
 * Difficulty : Medium
 * Topic : Greedy, Array
 * Link : https://leetcode.com/problems/gas-station/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station
 * to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
 * Given two integer arrays gas and cost, return the starting gas station's index if you can travel
 * around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution,
 * it is guaranteed to be unique
 *
 * Example 1:
 * Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * Output: 3
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            if (gas[i] < cost[i])
                continue;

            int j = (i + 1) % n;
            int currGas = gas[i] - cost[i] + gas[j];
            while (i != j)
            {
                int nextSt = (j + 1) % n;
                if (currGas >= cost[j])
                {
                    currGas = currGas - cost[j] + gas[nextSt];
                    j = nextSt;
                }
                else
                    break;
            }
            if (i == j)
                return i;
        }
        return -1;
    }
};
// Time Complexity : O()
// Space Complexity : O()

// ------------------------------------ Approach 2 ------------------------------------
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < n; i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        // total gas is less than total cost
        if (totalCost > totalGas)
            return -1;

        int startStation = 0;
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            total = total + gas[i] - cost[i];

            if (total < 0)
            {
                // station i can't be start Station
                startStation = i + 1;
                total = 0;
            }
        }
        return startStation;
    }
};