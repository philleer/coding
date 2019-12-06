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

class Solution {
public:	
	// 62. Unique Paths
	/*=====================================================================
	 * Description: A robot is located at the top-left corner of a mxn grid
	 *	(marked 'Start' in the diagram below).
	 *	The robot can only move either down or right at any point in
	 *	time. The robot is trying to reach the bottom-right corner of
	 *	the grid (marked 'Finish' in the diagram below).
	 *	How many possible unique paths are there?
	 *
	 * Note:
	 *	m and n will be at most 100.
	 *
	 * Example:
	 *	Input: m = 3, n = 2	Output: 3
	 *	Explanation: From the top-left corner, there are a total of 3
	 *	ways to reach the bottom-right corner:
	 *		1. Right -> Right -> Down
	 *		2. Right -> Down -> Right
	 *		3. Down -> Right -> Right
	 *
	 *	Input: m = 7, n = 3	Output: 28
	 *=====================================================================
	 */
	int uniquePaths(int m, int n) {
		std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
		for (int i=0; i < m; ++i) dp[i][0] = 1;
		for (int i=0; i < n; ++i) dp[0][i] = 1;

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}

		return dp[m-1][n-1];
	}
	// 63. Unique Paths II
	/*=====================================================================
	 * Description: Now consider if some obstacles are added to the grids.
	 *	How many unique paths would there be?
	 *	An obstacle and empty space is marked as 1 and 0 respectively
	 *	in the grid.
	 *
	 * Example:
	 *	Input:[[0,0,0], [0,1,0], [0,0,0]]	Output: 2
	 *	Explanation: There's one obstacle in the middle of the 3x3 grid
	 *	above. There are two ways to reach the bottom-right corner:
	 *		1. Right -> Right -> Down -> Down
	 *		2. Down -> Down -> Right -> Right
	 *=====================================================================
	 */
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0][0]==1) return 0;

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		std::vector<std::vector<long long>> dp(m,
						       std::vector<long long>(
						       n, 0));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (obstacleGrid[i][j]==0) {
					if (i==0 || j==0) {
						dp[i][j] = (i==0 ? (
							j==0 ? 1 : dp[i][j-1])
							: dp[i-1][j]);
					} else {
						dp[i][j] = dp[i-1][j] +
							   dp[i][j-1];
					}
				}
			}
		}

		return dp[m-1][n-1];
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		int m, n;
		ss >> m >> n;
		int res = uniquePaths(m, n);
		std::cout << "There are " << res << " unique paths."
			<< std::endl;
	}
	
	return 0;
}
