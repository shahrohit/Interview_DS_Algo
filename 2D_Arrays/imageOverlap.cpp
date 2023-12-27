#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Image Overlap
// LeetCode No : 835
// Difficulty : Medium
// Topics : Array, Matrix
// Link : https://leetcode.com/problems/image-overlap/description/

// ------------------------------------- Problem Statement --------------------------------------------------
// You are given two images, img1 and img2, represented as binary, square matrices of size n x n
// We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units.
// We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.
// Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.
// Return the largest possible overlap.

// Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
// Output: 3
// Explanation: We translate img1 to right by 1 unit and down by 1 unit.

// ------------------------------------ Approach 1  ---------------------------------------------

class Solution
{
public:
    int countOverLap(vector<vector<int>> &A, vector<vector<int>> &B, int &rowOff, int &colOff)
    {
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // A[i][j] => B[i + rowOff][j + colOff]
                int Bi = i + rowOff;
                int Bj = j + colOff;
                if (Bi < 0 || Bi >= n || Bj < 0 || Bj >= n)
                    continue;
                if (A[i][j] == 1 && B[Bi][Bj] == 1)
                    count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int n = A.size();
        int maxOverLap = 0;
        for (int rowOff = -n + 1; rowOff < n; rowOff++)
        {
            for (int colOff = -n + 1; colOff < n; colOff++)
            {
                int currOverLap = countOverLap(A, B, rowOff, colOff);
                maxOverLap = max(maxOverLap, currOverLap);
            }
        }
        return maxOverLap;
    }
};

// T.C : O(n^4)
// S.C : O(1)