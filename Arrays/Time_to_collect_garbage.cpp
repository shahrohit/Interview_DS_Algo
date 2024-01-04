#include <vector>
#include <string>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Minimum Amount of Time to Collect Garbage
 * LeetCode No : 2391
 * Diffulty : Medium
 * Topic : Array, String, Prefix Sum
 * Link : https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage
 * at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage.
 * Picking up one unit of any type of garbage takes 1 minute.
 *
 * Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
 * Output: 21
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {

        int M_Idx = 0, P_Idx = 0, G_Idx = 0;

        int garb_collection_time = 0;

        for (int i = 0; i < garbage.size(); i++)
        {
            for (char &garb : garbage[i])
            {
                if (garb == 'M')
                    M_Idx = i;

                else if (garb == 'P')
                    P_Idx = i;
                else
                    G_Idx = i;

                garb_collection_time++;
            }
        }

        for (int i = 1; i < travel.size(); i++)
        {
            travel[i] = travel[i - 1] + travel[i];
        }

        garb_collection_time += (M_Idx > 0) ? travel[M_Idx - 1] : 0;
        garb_collection_time += (P_Idx > 0) ? travel[P_Idx - 1] : 0;
        garb_collection_time += (G_Idx > 0) ? travel[G_Idx - 1] : 0;

        return garb_collection_time;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)