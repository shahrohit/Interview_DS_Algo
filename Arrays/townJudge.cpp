#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Find the Town Judge
// LeetCode No : 997
// Difficulty : Easy
// Topics : Array, Graph
// Link : https://leetcode.com/problems/find-the-town-judge/description/

// ----------------------- Problem Statement --------------------------------------
// In a town, there are n people labeled from 1 to n.
// There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:
// 1. The town judge trusts nobody.
// 2. Everybody (except for the town judge) trusts the town judge.

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3

// ----------------------- Approach 1 ---------------------------------
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);

        for (auto &t : trust)
        {
            int u = t[0];
            int v = t[1];

            // u --> v
            inDegree[v]++;
            outDegree[u]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (inDegree[i] == n - 1 && outDegree[i] == 0)
                return i;
        }
        return -1;
    }
};
// T.C : O(n)
// S.C : O(n)

// ------------------------ Approach 2 ------------------------------
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> count(n + 1, 0);

        for (auto &t : trust)
        {
            int u = t[0];
            int v = t[1];
            // u --> v // u cant be judge, v have chance to be judge
            count[u]--;
            count[v]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (count[i] == n - 1)
                return i;
        }
        return -1;
    }
};
// T.C : O(n)
// S.C : O(n)