#include <vector>
#include <algorithm>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Widest Vertical Area Between Two Points Containing No Points
 * LeetCode No : 1637
 * Difficulty : Medium
 * Topics : Array, Sorting
 * Link : https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * Given n points on a 2D plane where points[i] = [xi, yi],
 * Return the widest vertical area between two points such that no points are inside the area.
 * A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height).
 * The widest vertical area is the one with the maximum width.
 * Note that points on the edge of a vertical area are not considered included in the area.
 *
 * Input: points = [[8,7],[9,9],[7,4],[9,7]]
 * Output: 1
 * Explanation: Both the red and the blue area are optimal.
 *
 * Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
 * Output: 3
 */

// ----------------------- Approach 1  ---------------------------------
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(begin(points), end(points));

        int n = points.size();
        int maxWidth = 0;

        for (int i = 1; i < n; i++)
        {
            int currWidth = points[i][0] - points[i - 1][0];
            maxWidth = max(maxWidth, currWidth);
        }
        return maxWidth;
    }
};
// TC : O(nlogn)
// SC : O(1)