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
#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
	// 51. N-Queens
	// 52. N-Queens II
	/*=====================================================================
	 * Description: The n-queens puzzle is the problem of placing n queens
	 *	on an n×n chessboard such that no two queens attack each other.
	 *	Given an integer n, return all distinct solutions to the
	 *	n-queens puzzle. Each solution contains a distinct board
	 *	configuration of the n-queens' placement, where 'Q' and '.'
	 *	both indicate a queen and an empty space respectively.
	 *
	 * Example:
	 *	Input: 4
	 *	Output: [[".Q..","...Q","Q...","..Q."],
	 *		 ["..Q.","Q...","...Q",".Q.."]]
	 *	Explanation: There exist two distinct solutions to the 4-queens
	 *	puzzle.
	 *=====================================================================
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
			if (col == result[i] ||
			    std::abs(result[i]-col) == row - i)
			{
				return false;
			}
		}
		return true;
	}

	/*=====================================================================
	 * Description: This problem returns the number of distinct solutions
	 *	to the n-queens puzzle.
	 *
	 * Example:
	 *	Input: 4 	Output: 2
	 *	Explanation: There exist two distinct solutions to the 4-queens
	 *	puzzle.
	 *	[[".Q..","...Q","Q...","..Q."], ["..Q.","Q...","...Q",".Q.."]]
	 *=====================================================================
	 */
	int totalNQueens(int n) {
		std::vector<std::vector<int>> solutions;
		if (1 == n) return 1;
		if (n <= 0 || (n > 1 && n < 4)) return 0;
		
		std::vector<int> result;
		nQueenHelper(result, solutions, n, 0);
		return solutions.size();
	}
    
	void nQueenHelper(std::vector<int> &result,
    			  std::vector<std::vector<int>> &solutions,
    			  int n, int row)
	{
		if (row >= n) {
			// Replace the display commands in nQueen function
			solutions.push_back(result);
			return ;
		}
		
		for (int i = 0; i < n; ++i) {
			// check function is still the same with the
			// previous solution
			if (check(row, i, result)) {
				result.push_back(i);
				nQueenHelper(result, solutions, n, row+1);
				result.pop_back();
			}
		}
	}

	// Extended solution with bit operation
	void solveNQueensBit(int n) {
		std::vector<std::vector<int>> solutions;
		std::vector<int> result(n, -1);
		int max = (max << n) - 1;
		nQueenBit(0, 0, 0, result, solutions, max);
		visualize(solutions);
	}

	void nQueenBit(int k, int ld, int rd,
		std::vector<int> &result,
		std::vector<std::vector<int>> &solutions,
		const int max)
	{
		if (k == max) {
			solutions.push_back(result);
			return;
		}

		int pos = max & ~(k | ld | rd);
		// count how many 1 in the binary form of k
		// it means how many rows have been processed till now
		int index = count1Bit(k);
		while (pos) {
			int p = pos & (~pos+1);
			pos -= p;
			result[index] = (p==1 ? 0 : 1+(int)log2(p>>1));
			nQueenBit(k | p, (ld | p) << 1, (rd | p) >> 1,
				  result, solutions, max);
		}
	}

	int count1Bit(int n) {
		int countOneBit = 0;
		while (n) {
			++countOneBit;
			n &= (n-1);
		}
		return countOneBit;
	}

	void visualize(std::vector<std::vector<int>> &solutions) {
		int n = solutions.size();
		for (int r = 0; r < n; ++r) {
			int l = solutions[r].size();
			for (int c = 0; c < l; ++c) std::cout << solutions[r][c] << " ";
			std::cout<< std::endl;

			for (int c = 0; c < l; ++c) {
				int pos = solutions[r][c];
				for (int i = 0; i < l; ++i) {
					if (i == pos) std::cout << "Q ";
					else std::cout << "* ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		std::cout << "Total solutions: " << solutions.size() << std::endl;
	}
};

int main(int argc, const char *argv[]) {
	int n = 4;
	std::vector<std::vector<std::string>> strret =
		Solution().solveNQueens(n);
	std::cout << "The results are: "<< std::endl;
	for (int i = 0; i < strret.size(); ++i) {
		for (int j = 0; j < strret[i].size(); ++j) {
			std::cout << strret[i][j] << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}