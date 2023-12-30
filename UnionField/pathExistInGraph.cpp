#include <vector>

using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Find if Path Exists in Graph
// LeetCode No : 1971
// Difficulty : Easy
// Topics : DFS, BFS, Union Field, Graph
// Link : https://leetcode.com/problems/find-if-path-exists-in-graph/description/

// ----------------------- Problem Statement --------------------------------------

// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive).
// The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui
// and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
// You want to determine if there is a valid path that exists from vertex source to vertex destination.
// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2

// ----------------------- Approach 1 : Union Field ---------------------------------
class Solution
{
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y)
    {
        int Px = find(x);
        int Py = find(y);

        if (Px == Py)
            return;

        if (rank[Px] > rank[Py])
            parent[Py] = Px;

        else if (rank[Py] > rank[Px])
            parent[Px] = Py;

        else
        {
            parent[Px] = Py;
            rank[Py]++;
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            Union(u, v);
        }
        return find(source) == find(destination);
    }
};
// T.C : O(V + E)
// S.C :(V + E)