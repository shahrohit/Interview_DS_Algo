#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : The K Weakest Rows in a Matrix
// LeetCode No : 1337
// Difficulty : Easy
// Topics : Array, Binary Search, Sorting, Heap, Matrix
// Link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/

// ----------------------- Problem Statement --------------------------------------
// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians).
// The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
// A row i is weaker than a row j if one of the following is true:
// - The number of soldiers in row i is less than the number of soldiers in row j.
// - Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

// Input: mat =
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]],
// k = 3
// Output: [2,0,3]
// Explanation:
// The number of soldiers in each row is:
// - Row 0: 2
// - Row 1: 4
// - Row 2: 1
// - Row 3: 2
// - Row 4: 5
// The rows ordered from weakest to strongest are[2, 0, 3, 1, 4].

// ----------------------- Approach 1 : Sorting ---------------------------------

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        vector<pair<int, int>> rows;

        for (int i = mat.size() - 1; i >= 0; i--)
        {
            // binary Search
            int count = lower_bound(begin(mat[i]), end(mat[i]), 0, greater<int>()) - begin(mat[i]);
            rows.push_back({count, i});
        }
        vector<int> result;
        sort(begin(rows), end(rows));

        for (int i = 0; i < k; i++)
        {
            result.push_back(rows[i].second);
        }
        return result;
    }
};

// T.C : O(m * log(n) + m * log(m) + k)
// S.C : O(m)

// ----------------------- Approach 1 : Heap ---------------------------------
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        // max Heap
        priority_queue<pair<int, int>> pq;

        for (int i = mat.size() - 1; i >= 0; i--)
        {
            // binary Search
            int count = lower_bound(begin(mat[i]), end(mat[i]), 0, greater<int>()) - begin(mat[i]);

            pq.push({count, i});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result(k);
        int idx = k - 1;
        while (!pq.empty())
        {
            result[idx--] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};
// T.C : O(m * log(n) + m * log(k) + log(k))