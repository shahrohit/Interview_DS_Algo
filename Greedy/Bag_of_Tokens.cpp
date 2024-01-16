#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Bag of Tokens
 * Leetcode No : 948
 * Difficulty : Medium
 * Topic : Greedy, Array, Sorting
 * Link : https://leetcode.com/problems/bag-of-tokens/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).
 * Your goal is to maximize your total score by potentially playing each token in one of two ways:
 * - If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
 * - If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
 * Each token may be played at most once and in any order. You do not have to play all the tokens.
 * Return the largest possible score you can achieve after playing any number of tokens.
 *
 * Input: tokens = [100], power = 50
 * Output: 0
 *
 * Input: tokens = [100,200], power = 150
 * Output: 1
 *
 * Input: tokens = [100,200,300,400], power = 200
 * Output: 2
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());

        int left = 0, right = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;

        while (left <= right)
        {
            // loose power and gain score
            if (power >= tokens[left])
            {
                power = power - tokens[left++];
                score++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0) // loose score and gain power
            {
                power = power + tokens[right--];
                score--;
            }
            else
                break;
        }
        return maxScore;
    }
};
// Time Complexity : O(nlog(n))
// Space Complexity : O(1)