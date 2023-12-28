#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Valid Sudoku
// LeetCode No : 36
// Difficulty : Medium
// Topics : Array, Matrix, Hash Table
// Link : https://leetcode.com/problems/valid-sudoku/description/

// ----------------------- Problem Statement --------------------------------------

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// 1. Each row must contain the digits 1-9 without repetition.
// 2. Each column must contain the digits 1-9 without repetition.
// 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// -------------------------------- Approach 1  ---------------------------------
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> rowSet;
            unordered_set<int> colSet;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != '.')
                {
                    int rowVal = board[i][j] - '0';
                    if (rowSet.find(rowVal) != rowSet.end())
                        return false;
                    rowSet.insert(rowVal);
                }
                if (board[j][i] != '.')
                {
                    int colVal = board[j][i] - '0';
                    if (colSet.find(colVal) != colSet.end())
                        return false;
                    colSet.insert(colVal);
                }
            }
        }

        for (int i = 0; i < n; i += 3)
        {
            for (int j = 0; j < n; j += 3)
            {
                unordered_set<int> boxSet;
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (board[i + k][j + l] != '.')
                        {
                            int boxVal = board[i + k][j + l] - '0';
                            if (boxSet.find(boxVal) != boxSet.end())
                                return false;
                            boxSet.insert(boxVal);
                        }
                    }
                }
            }
        }
        return true;
    }
};
// T.C : O(1), board size is always 9 x 9
// S.C : O(1)

// ---------------------------------- Approach 2 ------------------------------------------
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> set;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1, board[i][j]) + "_COL_" + to_string(j);
                string box = string(1, board[i][j]) + "_BOX_" + to_string(i / 3) + "_" + to_string(j / 3);

                if (set.find(row) != set.end() || set.find(col) != set.end() || set.find(box) != set.end())
                {
                    return false;
                }
                set.insert(row);
                set.insert(col);
                set.insert(box);
            }
        }
        return true;
    }
};
// T.C : O(1)
// S.C : O(1)