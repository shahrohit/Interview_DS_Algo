#include <vector>
#include <unordered_map>
#include <queue>

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

// ----------------------- Approach 1 : DFS ---------------------------------
class Solution
{
public:
    bool DFS(int u, int &destination, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
    {
        if (u == destination)
            return true;
        visited[u] = true;

        for (auto &v : adj[u])
        {
            if (!visited[v] && DFS(v, destination, visited, adj) == true)
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        // adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) // O(E)
        {
            int u = edge[0];
            int v = edge[1];
            // for undirected graph
            adj[u].push_back(v); // u ---> v
            adj[v].push_back(u); // v ---> u
        }
        vector<bool> visited(n, false);                // visited data structure
        return DFS(source, destination, visited, adj); // O(V + E)
    }
};
// T.C : O(V + E)
// S.C : (V + E)

// ------------------------ Approach 2 : BFS ------------------------------

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); // u ---> v
            adj[v].push_back(u); // v ---> u
        }
        vector<bool> visited(n, false);

        // BFS
        queue<int> que;
        que.push(source);
        visited[source] = true;
        while (!que.empty())
        {
            int u = que.front();
            que.pop();

            if (u == destination)
                return true;

            for (auto &v : adj[u])
            {
                if (!visited[v])
                {
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
        return false;
    }
};
// T.C : O(V + E)
// S.C : O(V + E)