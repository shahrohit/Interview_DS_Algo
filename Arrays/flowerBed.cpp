#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Can Place Flowers
// LeetCode No : 605
// Difficulty : Easy
// Topics : Array, Greedy
// Link : https://leetcode.com/problems/can-place-flowers/description/

// ----------------------- Problem Statement --------------------------------------

// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n,
// return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false

// ------------------------------ Approach 1 ----------------------------------------
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;

        int m = flowerbed.size();
        for (int i = 0; i < m; i++)
        {
            if (flowerbed[i] == 1)
                continue;

            bool isleftEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool isRightEmpty = (i + 1 == m || flowerbed[i + 1] == 0);

            if (isleftEmpty && isRightEmpty)
            {
                flowerbed[i] = 1;
                n = n - 1;
                if (n == 0)
                    return true;
            }
        }
        return false;
    }
};
// T.C : O(n)
// S.C : O(1)