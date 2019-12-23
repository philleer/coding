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
	// 121. Best Time to Buy and Sell Stock
	/*=====================================================================
	 * Description: Say you have an array for which the ith element is the
	 *	price of a given stock on day i.
	 *	If you were only permitted to complete at most one transaction
	 *	(i.e., buy one and sell one share of the stock), design an
	 *	algorithm to find the maximum profit.
	 *	Note that you cannot sell a stock before you buy one.
	 *
	 * Example:
	 *	Input: [7,1,5,3,6,4]	Output: 5
	 *	Explanation: Buy on day 2 (price = 1) and sell on day 5
	 *	(price = 6), profit = 6-1 = 5. Not 7-1 = 6, as selling price
	 *	needs to be larger than buying price.
	 *
	 *	Input: [7,6,4,3,1] 	Output: 0
	 *	Explanation: In this case, no transaction is done, i.e. max
	 *	profit = 0.
	 *=====================================================================
	 */
	int maxProfit(std::vector<int>& prices) {
		if (prices.size() < 2) return 0;

		int size = prices.size();
		std::vector<int> dp(size, 0);
		dp[0] = prices[0];
		int maxpro = 0;
		for (int i = 1; i < size; ++i) {
			dp[i] = std::min(dp[i-1], prices[i]);
			maxpro = std::max(prices[i]-dp[i-1], maxpro);
		}

		return maxpro;
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
		result += (std::to_string(list[index].back()) + "], ");
	}
	// -2 的意思是最后一行多了两个字符 ", "
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<int> prices;
		while (std::getline(ss, str, ' ')) {
			prices.push_back(std::atoi(str.c_str()));
		}

		std::string in = integerVectorToString(prices);
		std::cout << "The given prices are:\n"
			<< in << std::endl;
		int res = Solution().maxProfit(prices);
		std::cout << "The max profit can be gained is : "
			<< res << std::endl;
	}

	return 0;
}

