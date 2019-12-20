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
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
	// 64. Minimum Path Sum
	/*=====================================================================
	 * Description: Given a mxn grid filled with non-negative numbers, find
	 *	a path from top left to bottom right which minimizes the sum of
	 *	all numbers along its path.
	 *
	 * Note: You can only move either down or right at any point in time.
	 *
	 * Example:
	 * 	Input: [[1,3,1], [1,5,1], [4,2,1]]	Output: 7
	 *	Explanation: Because the path 1→3→1→1→1 minimizes the sum.
	 *=====================================================================
	 */
	int minPathSum(std::vector<std::vector<int>>& grid) {
		if (grid.empty()) return 0;

		int m = grid.size(), n = grid[0].size();
		std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i==0 || j==0) {
					res[i][j] = grid[i][j] + (
						i==0 ? (j==0 ? 0 : res[i][j-1])
						: res[i-1][j]);
				} else {
					res[i][j] = grid[i][j] +
						std::min(res[i-1][j],
							 res[i][j-1]);
				}
			}
		}

		return res[m-1][n-1];
	}
};

int main(int argc, const char *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		int m, n;
		ss >> m >> n;
		std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				ss >> grid[i][j];
				std::cout << grid[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		int num = Solution().minPathSum(grid);
		std::cout << "The result minimum path sum is: " << num
			<< std::endl;
	}

	return 0;
}

