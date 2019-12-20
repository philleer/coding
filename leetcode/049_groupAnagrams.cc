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
#include <unordered_map>

class Solution {
public:
	// 49. Group Anagrams
	/*=====================================================================
	 * Description: Given an array of strings, group anagrams together.
	 *
	 * Example:
	 *	Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
	 *	Output: [["ate","eat","tea"], ["nat","tan"], ["bat"]]
	 *	
	 *	Input: candidates = [2,3,5], target = 8
	 *	Output: one solution is [[2,2,2,2], [2,3,3], [3,5]]
	 *
	 * Note:
	 *	All inputs will be in lowercase.
	 *	The order of your output does not matter.
	 *=====================================================================
	 */
	std::vector<std::vector<std::string>> groupAnagrams(
		std::vector<std::string>& strs)
	{
		std::vector<std::vector<std::string>> res;
		if (strs.empty()) return res;

		std::unordered_map<std::string, std::vector<std::string>> mp;
		// map的插入，使用insert插入时如果关键字已经存在，则无法插入
		// 使用下标插入元素时，如果已经存在，会直接被覆盖掉
		for (std::string &s : strs) {
			std::string str(s);
			std::sort(str.begin(), str.end());
			mp[str].push_back(s);
		}

		for (auto &p : mp) {
			res.push_back(std::move(p.second));
		}

		return res;
	}
};

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<std::string> strs;
		while (std::getline(ss, str, ' ')) {
			strs.push_back(str);
		}

		std::cout << "The input strings:\n[";
		for (auto &s : strs) {
			std::cout << s << ", ";
		}
		std::cout << "]\n";
		std::vector<std::vector<std::string>> res =
			Solution().groupAnagrams(strs);
		for (int i = 0; i < res.size(); ++i) {
			std::cout << "[\n";
			for (int j = 0; j < res[i].size(); ++j) {
				std::cout << res[i][j] << ", ";
			}
			std::cout << "]\n";
		}
		std::cout << std::endl;
	}

	return 0;
}

