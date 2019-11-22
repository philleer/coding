/******************************************************************************
 * The source is part of my coding practice, a lightweight C++ solution for
 * leetcode program practice.
 *
 * For all of my code, after check it online by submit, I also compile and run
 * it by my offline machine
 * ============================================================================
 * ////////////// Microsoft Visual Studio 2010 when I use windows /////////////
 * //////////////	       G++5.4.0 when I am on Linux           /////////////
 * ============================================================================
 *
 * If any question, feel free to send me an email << phillee2016@163.com >>
 * or just correct it via Pull Request or create an issue.
 ******************************************************************************
 */
// 51. N-Queens
// 52. N-Queens II
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
	/*=========================================================================
	 * Description: The n-queens puzzle is the problem of placing n queens on
	 *	an n×n chessboard such that no two queens attack each other.
	 *	Given an integer n, return all distinct solutions to the n-queens
	 *	puzzle. Each solution contains a distinct board configuration of
	 *	the n-queens' placement, where 'Q' and '.' both indicate a queen
	 *	and an empty space respectively.
	 * Example:
	 *	Input: 4
	 *	Output: [[".Q..","...Q","Q...","..Q."], ["..Q.","Q...","...Q",".Q.."]]
	 * Explanation: There exist two distinct solutions to the 4-queens puzzle.
	 *=========================================================================
	 */
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		std::vector<std::vector<std::string>> ret;
		if (n > 1 && n < 4) return ret;
		if (1 == n) {
			std::vector<std::string> tmp{"Q"};
			ret.push_back(tmp);
			return ret;
		}
		
		std::vector<int> result;
		nQueen(result, ret, n, 0);
		return ret;
	}

	void nQueen(std::vector<int> &result,
		std::vector<std::vector<std::string>> &ret,
		int n, int row)
	{
		if (row >= n) {
			std::vector<std::string> level;
			int n = result.size();
			for (int j = 0; j < n; ++j) {
				std::string tmp;
				for (int k = 0; k < n; ++k)
					tmp += (k == result[j] ? 'Q' : '.');
				level.push_back(tmp);
			}
			ret.push_back(level);
			return ;
		}
		
		for (int i = 0; i < n; ++i) {
			if (check(row, i, result)) {
				result.push_back(i);
				nQueen(result, ret, n, row+1);
				result.pop_back();
			}
		}
	}

	bool check(int row, int col, std::vector<int> &result) {
		for (int i = 0; i < result.size(); ++i) {
			if (col == result[i] || std::abs(result[i]-col) == row - i)
				return false;
		}
		return true;
	}

	/*=========================================================================
	 * Description: This problem returns the number of distinct solutions to
	 *	the n-queens puzzle.
	 * Example:
	 *	Input: 4
	 *	Output: 2
	 *  Explanation: There exist two distinct solutions to the 4-queens puzzle.
	 *			[[".Q..","...Q","Q...","..Q."], ["..Q.","Q...","...Q",".Q.."]]
	 *=========================================================================
	 */
    int totalNQueens(int n) {
        std::vector<std::vector<int>> solutions;
		if (1 == n)	return 1;
        if (n <= 0 || (n > 1 && n < 4)) return 0;
		
		std::vector<int> result;
		nQueenHelper(result, solutions, n, 0);
		return solutions.size();
    }
    
    void nQueenHelper(std::vector<int> &result, std::vector<std::vector<int>> &solutions, int n, int row) {
		if (row >= n) {
			// Replace the display commands in nQueen function
			solutions.push_back(result);
			return ;
		}
		
		for (int i = 0; i < n; ++i) {
			// check function is still the same with the previous solution
			if (check(row, i, result)) {
				result.push_back(i);
				nQueenHelper(result, solutions, n, row+1);
				result.pop_back();
			}
		}
	}
};

int main(int argc, char *argv[]) {
	int n = 4;
	Solution solver;
	std::vector<std::vector<std::string>> strret = solver.solveNQueens(n);
	std::cout << "The results are: "<< std::endl;
	for (int i = 0; i < strret.size(); ++i) {
		for (int j = 0; j < strret[i].size(); ++j) {
			std::cout << strret[i][j] << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
