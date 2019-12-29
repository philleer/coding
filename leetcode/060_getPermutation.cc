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
	// 60. Permutation Sequence
	/*=====================================================================
	 * Description: The set [1,2,3,...,n] contains a total of n! unique
	 *	permutations. By listing and labeling all of the permutations
	 *	in order, we get the following sequence for n = 3:
	 *		"123" "132" "213" "231" "312" "321"
	 *	Given n and k, return the kth permutation sequence.
	 *
	 * Note:
	 *	Given n will be between 1 and 9 inclusive.
	 *	Given k will be between 1 and n! inclusive.
	 *
	 * Example:
	 *	Input: n = 3, k = 3	Output: "213"
	 *
	 *	Input: n = 4, k = 9 	Output: "2314"
	 *=====================================================================
	 */
	// 第一种方法，回溯法枚举
	std::string getPermutation(int n, int k) {
		if (n > 9 || n < 1 || k < 1) return "";

		std::string strset;
		for (int i = 1; i <= n; ++i) strset += std::to_string(i);

		std::string ret;
		std::vector<std::string> strs;
		std::vector<int> visited(n, 0);
		backtrack(strset, strs, ret, visited, k);

		return strs[k-1];
	}

	// 对第一种方法的一些微小的改进
	// 不再保留中间满足要求的每一个结果，只对最后一个结果处理
	string getPermutation(int n, int k) {
		if (n > 9 || n < 1 || k < 1) return "";

		std::string strset;
		for (int i = 1; i <= n; ++i) strset += std::to_string(i);
		
		int cnt = 0;
		std::string ret = "";
		std::vector<int> visited(n, 0);
		backtrack(strset,ret, visited, k, cnt);

		return ret;
	}

private:
	// 第一种方法辅助函数
	bool backtrack(
		std::string &strset,
		std::vector<std::string> &results,
		std::string &result,
		std::vector<int> &visited,
		int k)
	{
		if (result.size() >= strset.length()) {
			results.push_back(result);
			if (results.size() >= k) return true;
			return false;
		}

		for (int i = 0; i < strset.length(); ++i) {
			if (visited[i] == 1) continue;

			visited[i] = 1;
			result += strset[i];
			bool next = backtrack(strset, results, result, visited, k);
			if (next) return true;
			result.pop_back();
			visited[i] = 0;
		}

		return false;
	}

	// 第一种方法辅助函数改进
	bool backtrack(
		std::string &strset,
		std::string &result,
		std::vector<int> &visited,
		int k,
		int &cnt)
	{
		if (result.size() >= visited.size()) {
		    if (++cnt >= k) return true;
		    return false;
		}

		for (int i = 0; i < visited.size(); ++i) {
			if (visited[i] == 1) continue;
			visited[i] = 1;
			result += strset[i];
			if (backtrack(strset, result, visited, k, cnt)) return true;
			result.pop_back();
			visited[i] = 0;
		}

		return false;
	}

	// 第二种方法，利用排列规律进行分组，逐步减小搜索范围
	string getPermutation(int n, int k) {
		if (n > 9 || n < 1 || k < 1) return "";

		std::vector<int> fact(n+1, 1);
		for (int i = 1; i <= n; ++i) {
			fact[i] = fact[i-1] * i;
		}

		std::string str;
		for (int i = 1; i <= n; ++i) str.push_back(i+'0');

		std::string ans;
		while (n) {
			int tmp = (k-1) / fact[n-1];
			ans.push_back(str[tmp]);
			k -= tmp * fact[n-1];
			--n;
			str.erase(str.begin()+tmp);
		}

		return ans;
	}
};

int stringToInteger(std::string input) {
	return std::stoi(input);
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		int n = stringToInteger(line);
		std::getline(std::cin, line);
		int k = stringToInteger(line);

		std::string ret = Solution().getPermutation(n, k);

		std::string out = (ret);
		std::cout << out << std::endl;
	}

	return 0;
}

