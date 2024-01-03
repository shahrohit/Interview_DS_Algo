#include <vector>
#include <algorithm>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Image Smoother
 * LeetCode No : 661
 * Difficulty : Easy
 * Topics : Array, Matrix
 * Link : https://leetcode.com/problems/image-smoother/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image
 * by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother).
 * If one or more of the surrounding cells of a cell is not present, we do not consider it in the average
 * (i.e., the average of the four cells in the red smoother).
 * Given an m x n integer matrix img representing the grayscale of an image,
 * return the image after applying the smoother on each cell of it.
 *
 * Input: img = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[0,0,0],[0,0,0],[0,0,0]]
 *
 * Input: img = [[100,200,100],[200,50,200],[100,200,100]]
 * Output: [[137,141,137],[141,138,141],[137,141,137]]
 */

// ----------------------- Approach 1  ---------------------------------
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {

        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result(m, vector<int>(n));

        int directions[9][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0, count = 0;
                for (auto &dir : directions)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                        continue;

                    sum += img[new_i][new_j];
                    count++;
                }

                result[i][j] = sum / count;
            }
        }
        return result;
    }
};
// TC : O(n * m)
// SC : O(n * m)