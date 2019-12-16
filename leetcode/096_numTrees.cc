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
	// 96. Unique Binary Search Trees
	/*=====================================================================
	 * Description: Given n, how many structurally unique BST's (binary
	 *	search trees) that store values 1 ... n?
	 *
	 * Note:
	 *	All numbers (including target) will be positive integers.
	 *	The solution set must not contain duplicate combinations.
	 * Example:
	 *	Input: 3 	Output: 5
	 *	Explanation:
	 *	Given n = 3, there are a total of 5 unique BST's:
	 * 
	 *	   1         3     3      2      1
	 *	    \       /     /      / \      \
	 *	     3     2     1      1   3      2
	 *	    /     /       \                 \
	 *	   2     1         2                 3
	 *=====================================================================
	 */
	int numTrees(int n) {
		// new出来的基本类型数据的初始化，后面加小括号，且括号中无内容
		int *dp = new int[n+1]();
		dp[0] = 1, dp[1] = 1;

		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] += dp[j]*dp[i-1-j];
			}
		}

		return dp[n];
	}
};

int stringToInteger(std::string input) {
	return std::stoi(input);
}

int main(int argc, char *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		int n = stringToInteger(line);
		int ret = Solution().numTrees(n);
		std::cout << std::to_string(ret) << std::endl;
	}

	return 0;
}
