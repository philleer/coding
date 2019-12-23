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
#include <vector>

class Solution {
public:
	// 120. Triangle
	/*=====================================================================
	 * Description: Given a triangle, find the minimum path sum from top to
	 * 	bottom. Each step you may move to adjacent numbers on the row
	 *	below.
	 *
	 * Example:
	 *	Input: [
	 *		     [2],
	 *		    [3,4],
	 *		   [6,5,7],
	 *		  [4,1,8,3]
	 *		]
	 *	Output: 11
	 *	Explanation: The minimum path sum from top to bottom is 11
	 *	(i.e., 2 + 3 + 5 + 1 = 11).
	 *
	 * Note:
	 *	Bonus point if you are able to do this using only O(n) extra
	 *	space, where n is the total number of rows in the triangle.
	 *=====================================================================
	 */
	int minimumTotal(std::vector<std::vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		if (1 == triangle.size()) return triangle[0][0];

		int rows = triangle.size();
		std::vector<std::vector<int>> dp(rows);
		for (int i = rows-1; i >= 0; --i) {
			dp[i].resize(triangle[i].size());
			for (int j = triangle[i].size()-1; j >= 0; --j ) {
				if (i == rows-1) {
					dp[i][j] = triangle[i][j];
					continue;
				}
				dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1])+
					   triangle[i][j];
			}
		}

		return dp[0][0];
	}
};

std::string integerVectorToString(std::vector<std::vector<int>> list,
				  int length = -1)
{
	if (length == -1) length = list.size();
	if (length == 0) return "[]";

	std::string result;
	for(int index = 0; index < length; ++index) {
		result += "[";
		for (int j = 0; j < list[index].size()-1; ++j) {
			result += std::to_string(list[index][j]) + ", ";
		}
		result += std::to_string(list[index].back()) + "], ";
	}
	// -2 的意思是最后一行多了两个字符 ", "
	return "[" + result.substr(0, result.length() - 2) + "]";
}

void integerVectorToTriangle(std::vector<std::vector<int>> &list) {
	int length = list.size();
	if (length == 0) return "[]";

	std::cout << "[" << std::endl;
	for (int i = 0; i < length; ++i) {
		std::cout << "  [ ";
		for (int j = 0; j < list[i].size(); ++j) {
			std::cout << list[i][j] << " ";
		}
		std::cout << "]," << std::endl;
	}
	std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[]) {
	std::string line;
	// Input format: for triangle [[2],[3,4],[6,5,7],[4,1,8,3]]
	//		 you should type in the standard input as follows
	//		 2;3 4;6 5 7;4 1 8 3;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<std::vector<int>> triangle;
		while (std::getline(ss, str, ';')) {
			std::stringstream sstmp;
			sstmp.str(str);
			std::vector<int> level;
			std::string ch;
			while (std::getline(sstmp, ch, ' ')) {
				level.push_back(std::atoi(ch.c_str()));
			}
			triangle.push_back(level);
		}

		std::string in = integerVectorToString(triangle);
		std::cout << "The input triangle vector is:\n"
			<< in << std::endl;
		integerVectorToTriangle(triangle);
		int res = Solution().minimumTotal(triangle);
		std::cout << "The minimum Total of the given triangle is: "
			<< res << std::endl;

	}

	return 0;
}

