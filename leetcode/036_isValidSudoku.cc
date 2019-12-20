/******************************************************************************
 * The source is part of my coding practice, a lightweight C++ solution for
 * leetcode program practice.
 *
 * For all of my code, after check it online by submit, I also compile and run
 * it by my offline machine
 * ============================================================================
 * ////////////// Microsoft Visual Studio 2010 when I use windows /////////////
 * //////////////           G++5.4.0 when I am on Linux           /////////////
 * ============================================================================
 *
 * If any question, feel free to send me an email << phillee2016@163.com >>
 * or just correct it via Pull Request or create an issue.
 ******************************************************************************
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
        // 36. Valid Sudoku
        /*=====================================================================
         * Description: Determine if a 9x9 Sudoku board is valid. Only the
         *      filled cells need to be validated according to the following
         *      rules:
         *      Each row must contain the digits 1-9 without repetition.
         *      Each column must contain the digits 1-9 without repetition.
         *      Each of the 9 3x3 sub-boxes of the grid must contain the digits
         *      1-9 without repetition.
         *      The Sudoku board could be partially filled, where empty cells
         *      are filled with the character '.'.
         *
         * Example:
         *      Input: [["5","3",".",".","7",".",".",".","."],
         *              ["6",".",".","1","9","5",".",".","."],
         *              [".","9","8",".",".",".",".","6","."],
         *              ["8",".",".",".","6",".",".",".","3"],
         *              ["4",".",".","8",".","3",".",".","1"],
         *              ["7",".",".",".","2",".",".",".","6"],
         *              [".","6",".",".",".",".","2","8","."],
         *              [".",".",".","4","1","9",".",".","5"],
         *              [".",".",".",".","8",".",".","7","9"]]
         *      Output: true
         *      
         *      Input: [["8","3",".",".","7",".",".",".","."],
         *              ["6",".",".","1","9","5",".",".","."],
         *              [".","9","8",".",".",".",".","6","."],
         *              ["8",".",".",".","6",".",".",".","3"],
         *              ["4",".",".","8",".","3",".",".","1"],
         *              ["7",".",".",".","2",".",".",".","6"],
         *              [".","6",".",".",".",".","2","8","."],
         *              [".",".",".","4","1","9",".",".","5"],
         *              [".",".",".",".","8",".",".","7","9"]]
         *      Output: false
         *      Explanation: Same as Example 1, except with the 5 in the top
         *      left corner being modified to 8. Since there are two 8's in the
         *      top left 3x3 sub-box, it is invalid.
         *
         * Note:
         *      A Sudoku board (partially filled) could be valid but is not
         *      necessarily solvable.
         *      Only the filled cells need to be validated according to the
         *      mentioned rules.
         *      The given board contain only digits 1-9 and the character '.'.
         *      The given board size is always 9x9.
         *=====================================================================
         */
        // waste time to save space consumation
        // 12ms + 9.8MB
        bool isValidSudoku(std::vector<std::vector<char>>& board) {
                std::unordered_map<char, int> mp{{'1', 0}, {'2', 0}, {'3', 0},
                                                 {'4', 0}, {'5', 0}, {'6', 0},
                                                 {'7', 0}, {'8', 0}, {'9', 0}};

                for (int i = 0; i < 9; ++i) {
                        for (char k = '1'; k <= '9'; ++k) mp[k] = 0;
                        for (int j = 0; j < 9; ++j) {
                                char tmp = board[i][j];
                                if (tmp >= '1' && tmp <= '9') {
                                        ++mp[tmp];
                                        if (mp[tmp] >= 2) return false;
                                } else {
                                        continue;
                                }
                        }
                }

                for (int j = 0; j <9; ++j) {
                        for (char k = '1'; k <= '9'; ++k) mp[k] = 0;
                        for (int i = 0; i <9; ++i) {
                                char tmp = board[i][j];
                                if (tmp >= '1' && tmp <= '9') {
                                        ++mp[tmp];
                                        if (mp[tmp] >= 2) return false;
                                } else {
                                        continue;
                                }
                        }
                }

                for (int i = 0; i < 3; ++i) {
                        for (int j= 0; j < 3; ++j) {
                                int cx = 3*i, cy = 3*j;
                                for (char k = '1'; k <= '9'; ++k) mp[k] = 0;
                                for (int r = cx; r < cx+3; ++r) {
                                        for (int c = cy; c < cy+3; ++c) {
                                                char tmp = board[r][c];
                                                if (tmp >= '1' && tmp <= '9') {
                                                        ++mp[tmp];
                                                        if (mp[tmp] >= 2)
                                                                return false;
                                                } else {
                                                        continue;
                                                }
                                        }
                                }
                        }
                }

                return true;
        }

        // waste space to save time
        // 20ms + 12MB
        bool isValidSudoku(std::vector<std::vector<char>>& board) {
                std::vector<std::unordered_set<char>> horizen(9);
                std::vector<std::unordered_set<char>> vertical(9);
                std::vector<std::unordered_set<char>> block(9);

                for (int i = 0; i < board.size(); ++i) {
                        for (int j = 0; j < board[i].size(); ++j) {
                                char tmp = board[i][j];
                                int idx =  3 * (i / 3) + j / 3;
                                if (tmp >= '1' && tmp <= '9') {
                                        if (horizen[i].find(tmp) !=
                                                horizen[i].end() ||
                                            vertical[j].find(tmp) !=
                                                vertical[j].end() ||
                                            block[idx].find(tmp) !=
                                                block[idx].end())
                                        {
                                                return false;
                                        }
                                        horizen[i].insert(tmp);
                                        vertical[j].insert(tmp);
                                        block[idx].insert(tmp);
                                } else {
                                        continue;
                                }
                        }
                }

                return true;
        }
};

int main(int argc, const char *argv[]) {
        std::vector<std::vector<char>> board {
                {"5","3",".",".","7",".",".",".","."},
                {"6",".",".","1","9","5",".",".","."},
                {".","9","8",".",".",".",".","6","."},
                {"8",".",".",".","6",".",".",".","3"},
                {"4",".",".","8",".","3",".",".","1"},
                {"7",".",".",".","2",".",".",".","6"},
                {".","6",".",".",".",".","2","8","."},
                {".",".",".","4","1","9",".",".","5"},
                {".",".",".",".","8",".",".","7","9"}};
        
        for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                        std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << (Solution().isValidSudoku(board) ? "true" : "false")
                << std::endl;

        return 0;
}

