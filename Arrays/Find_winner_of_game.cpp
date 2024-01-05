#include <vector>
#include <algorithm>

using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Find the Winner of an Array Game
 * LeetCode No : 1535
 * Diffulty : Medium
 * Topic : Array, Simulation
 * Link : https://leetcode.com/problems/find-the-winner-of-an-array-game/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 *  Given an integer array arr of distinct integers and an integer k.
 * A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]).
 * In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0
 * and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.
 *
 * Return the integer which will win the game.
 *
 * It is guaranteed that there will be a winner of the game.
 *
 * Example 1:
 * Input: arr = [2,1,3,5,4,6,7], k = 2
 * Output: 5
 *
 */

// ------------------------------------ Approach 1 ------------------------------------

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maxElem = *max_element(begin(arr), end(arr));
        int n = arr.size();

        int win_count = 0;
        int winner = arr[0];

        if (k >= n)
            return maxElem;

        for (int i = 1; i < n; i++)
        {

            if (arr[i] > winner)
            {
                winner = arr[i];
                win_count = 1;
            }
            else
            {
                win_count++;
            }

            if (win_count == k || winner == maxElem)
                break;
        }
        return winner;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)