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
#include <vector>       // std::vector
#include <cstddef>      // size_t

class Solution {
public:
        /*=====================================================================
         * Description:  Given a 2d grid of '1's (land) and '0's (water), count
         *      the number of islands. An island is surrounded by water and is
         *      formed by connecting adjacent lands horizontally or vertically.
         *      You may assume all four edges of the grid are all surrounded by
         *      water.
         *
         * Example:
         *      Input: [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"],
         *              ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]
         *      Output: 1
         *
         *      Input: [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"],
         *              ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]
         *      Output: 3
         *=====================================================================
         */
        int numIslands(std::vector<std::vector<char>>& grid) {
                int num = 0;
                if(grid.empty()) return num;
                rows = grid.size();
                cols = grid[0].size();
                // 对visited数组进行初始化
                visited.resize(rows);
                for (size_t i = 0; i < rows; ++i) visited[i].resize(cols);

                for(size_t i = 0; i < rows; ++i) {
                        for(size_t j = 0; j < cols; ++j) {
                                // 注意这里判断相等时使用的是字符1和0
                                if(visited[i][j] != 1 && grid[i][j] == '1') {
                                        dfs(grid, i, j);
                                        ++num;
                                } else {
                                        visited[i][j] = 1;
                                }
                        }
                }
                return num;
        }

        void dfs(std::vector<std::vector<char>> &grid, int i, int j) {
                // 当遍历越界或者已经遍历过时直接返回
                if(i<0 || j<0 || i>=rows || j>=cols || 1==visited[i][j]) {
                        return;
                }

                visited[i][j] = 1;
                if(grid[i][j] == '1') {
                        dfs(grid, i, j - 1);
                        dfs(grid, i - 1, j);
                        dfs(grid, i, j + 1);
                        dfs(grid, i + 1, j);
                }
        }

        void depth_first_search(std::vector<std::vector<char>> &grid,
                                int i, int j)
        {
                if (i>=0 && i<rows && j>=0 && j<cols && 1==visited[i][j]) {
                        return;
                }

                visited[i][j] = 1;
                if (grid[i][j] == '1') {
                        // 注意这里判断越界时索引值要小于行数或者列数
                        if (i+1 < rows) dfs(grid, i+1, j);
                        if (j+1 < cols) dfs(grid, i, j+1);
                        if (i >= 1) dfs(grid, i-1, j);
                        if (j >= 1) dfs(grid, i, j-1);
                }
        }

public:
        int rows;
        int cols;
        std::vector<std::vector<int>> visited;
};

int main(int argc, char const *argv[]) {
        std::vector<std::vector<char>> vec1 = {
                {1, 1, 1, 1, 0},
                {1, 1, 0, 1, 0},
                {1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0}};

        std::vector<std::vector<char>> vec2 = {
                {1, 1, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 1, 1}};

        Solution solver;
        std::cout << "Num of islands in vector1: "
                << solver.numIslands(vec1) << std::endl;
        std::cout << "Num of islands in vector2: "
                << solver.numIslands(vec2) << std::endl;  

        return 0;
}