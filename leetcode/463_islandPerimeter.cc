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
#include <utility>	// std::make_pair

#define PI 3.14159265359

class Solution {
public:
        // 463. Island Perimeter
        /*=====================================================================
         * Description:  Given a map in form of 2-d integer grid where 0
         *      represents land and 0 represents water. Grid cells are
         *      connected horizontally or vertically(not diagonally). The grid
         *      is completely surrounded by water, and there's exactly one
         *      island (i.e.,  one or more connected land cells).
         *      The island doesn't have "lakes" (water inside that is not
         *      connected to the water around the island). One cell is a square
         *      with length 1. The grid is rectangular, width and height don't
         *      exceed 100. Please determine the perimeter of the island.
         *
         * Example:
         *      Input: [[0,1,0,0], [1,1,1,0], [0,1,0,0], [1,1,0,0]]
         *      Output: 16
         * 	Explanation: The perimeter is the 16 yellow stripes as shown
         *      below <https://leetcode.com/problems/island-perimeter/>
         *=====================================================================
         */
        int islandPerimeter(std::vector<std::vector<int>> &grid) {
                if (grid.empty()) return 0;

                size_t rows = grid.size();
                size_t cols = grid[0].size();
                orientation.resize(4);
                for (size_t i = 0; i < 4; ++i) {
                        float theta = i * PI / 2.f;
                        orientation[i] = std::make_pair(
                                -static_cast<size_t>(std::sin(theta)),
                        	static_cast<size_t>(std::cos(theta)));
                }

                // ========================= 初始版本 ======================== //
                // 最初是想利用BFS遍历grid，因为只有一个岛，这样可以省却很多不必要的
                // 遍历观察格点状态可知，有四个相邻1的点对周长没有贡献，有三个相邻1的
                // 贡献一条边，有两个相邻1的贡献两条边，而有一个相邻1的贡献三条边，
                // 没有相邻1的点为孤岛，将会产生四条边的贡献
                // num_cross = 0, num_corner = 0, num_end = 0;
                // count.resize(rows);
                // for (size_t idx = 0; idx < rows; ++idx) {
                // 	count[idx].resize(cols, 0);
                // }

                // for (size_t i = 0; i < rows; ++i) {
                // 	for (size_t j = 0; j < cols; ++j) {
                // 	    if (grid[i][j]==1) {
                // 		for (size_t k = 0; k < 4; ++k) {
                // 		    size_t x = i+orientation[k].first;
                // 		    size_t y = j+orientation[k].second;
                // 		    if (x>=0 && x<rows && y>=0 && y<cols &&
                // 			grid[x][y] == 1) {
                // 			++count[i][j];
                // 		    }
                // 		}
                // 		switch(count[i][j]) {
                // 		    case 3: ++num_cross;	break;
                // 		    case 2: ++num_corner;	break;
                // 		    case 1: ++num_end;		break;
                // 		    default: break;
                // 		}
                // 	    }
                // 	}
                // }
        	
                // 用来处理岛屿只包含一个cell的情况
                // if (num_cross == 0 && num_corner == 0 && num_end == 0)
                //      return 4;
                // 一般情况下从这里返回
                // return (num_cross + 2*num_corner + 3*num_end);

                // ======================== 改进版本 ======================= //
                // 仔细思考和观察可以发现:
                // (1) 其实上面的count数组是没有必要的存在，因为我对每个点计数完成后
                // 直接对其计数值进行判断，可以使用一个局部变量代替
                // (2) 相邻1的个数与贡献值可以用(4-count)公式来表达，不需要switch
                int perimeter = 0;
                for (size_t i = 0; i < rows; ++i) {
                        for (size_t j = 0; j < cols; ++j) {
                                if (grid[i][j]==1) {
                                        int count = 0;
                                        for (size_t k = 0; k < 4; ++k) {
                                                size_t x =
                                                        i+orientation[k].first;
                                                size_t y =
                                                        j+orientation[k].second;
                                                if (x>=0 && x<rows && y>=0 &&
                                                    y<cols && 1==grid[x][y])
                                                {
                                                        ++count;
                                                }
                                        }

                                        perimeter += (4 - count);
                                }
                        }
                }

                return perimeter;
        }

        int islandPerimeter1(std::vector<std::vector<int>> &grid) {
                if (grid.empty()) return 0;

                size_t rows= grid.size();
                size_t cols=grid[0].size();
                int perimeter=0;
                int north = 0, west = 0, south = 0, east = 0;
                for (size_t i = 0; i < rows; ++i){
                        for (size_t j = 0; j < cols; ++j){
                                if(grid[i][j] == 1){
                                        north = (i > 0) ? grid[i-1][j] : 0;
                                        west = (j > 0) ? grid[i][j-1] : 0;
                                        south = (i < rows-1) ? grid[i+1][j] : 0;
                                        east = (j < cols-1) ? grid[i][j+1] : 0;

                                        perimeter += 4*grid[i][j] -
                                                (north+west+south+east);
                                }
                        }
                }

                return perimeter;
        }

        int islandPerimeter2(std::vector<std::vector<int>> &grid) {
                if (grid.empty()) return 0;

                size_t rows= grid.size();
                size_t cols=grid[0].size();
                int perimeter=0;
                for (size_t i = 0; i < rows; ++i) {
                        for (size_t j = 0; j < cols; ++j) {
                                if(grid[i][j] == 1){
                                        if (i==0 || grid[i-1][j]==0) {
                                                ++perimeter;
                                        }
                                        if (i==rows-1 || grid[i+1][j]==0) {
                                                ++perimeter;
                                        }
                                        if (j==0 || grid[i][j-1]==0) {
                                                ++perimeter;
                                        }
                                        if (j==cols-1 || grid[i][j+1]==0) {
                                                ++perimeter;
                                        }
                                }
                        }
                }

                return perimeter;
        }

public:
        std::vector<std::vector<char>> count;
        std::vector<std::pair<size_t, size_t>> orientation;
        size_t num_cross;
        size_t num_corner;
        size_t num_end;
};

int main(int argc, char const *argv[]) {
        std::vector<std::vector<int>> vec1 = {
                {0, 1, 0, 0},
                {1, 1, 1, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0}};
        std::vector<std::vector<int>> vec2 = {{1}};
        std::vector<std::vector<int>> vec3 = {{1, 0}};

        Solution solver;
        std::cout << "island perimeter of the given grid: "
                << solver.islandPerimeter(vec1) << std::endl;
        std::cout << "island perimeter of the given grid: "
                << solver.islandPerimeter(vec2) << std::endl;
        std::cout << "island perimeter of the given grid: "
                << solver.islandPerimeter(vec3) << std::endl;

        return 0;
}