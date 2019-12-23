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
#include <string>

class Solution {
public:
	// 77. Combinations
	/*=====================================================================
	 * Description: Given two integers n and k, return all possible
	 *	combinations of k numbers out of 1 ... n.
	 *
	 * Example:
	 * 	Input: n = 4, k = 2
	 *	Output: [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]
	 *=====================================================================
	 */
	std::vector<std::vector<int>> combine(int n, int k) {
		std::vector<std::vector<int>> res;
		if (k > n) return res;

		std::vector<int> sol;
		helper(n, k, res, sol, 1);
		return res;
	}

	void helper(int n, int k, std::vector<std::vector<int>> &res,
		    std::vector<int> &sol,
		    int index)
	{
		if (sol.size() >= k) {
			res.push_back(sol);
			return ;
		}

		for (int i = index; i <= n; ++i) {
			sol.push_back(i);
			helper(n, k, res, sol, i+1);
			sol.pop_back();
		}
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		int n, k;
		ss >> n >> k;
		std::cout << "The input parameter is:\n" << n << ", "
			<< k << std::endl;
		
		std::vector<std::vector<int>> res = Solution().combine(n, k);
		std::cout << "The combinations is:\n[" << std::endl;
		for (int i = 0; i < res.size(); ++i) {
			std::cout << "  [ ";
			for (int j = 0; j < res[i].size(); ++j) {
				std::cout << res[i][j] << " "
			}
			std::cout << " ]\n";
		}
		std::cout << "]" << std::endl;
	}

	return 0;
}

