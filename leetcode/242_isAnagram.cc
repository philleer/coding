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
#include <map>
#include <unordered_map>
#include <pair>

class Solution {
public:
	// 242. Valid Anagram
	/*=====================================================================
	 * Description: Given two strings s and t, write a function to
	 *	determine if t is an anagram of s.
	 *
	 * Example:
	 *	Input: s = "anagram", t = "nagaram"	Output: true
	 *	Input: s = "rat", t = "car"	Output: false
	 *
	 * Note:
	 * 	You may assume the string contains only lowercase alphabets.
	 *
	 * Follow up:
	 *	What if the inputs contain unicode characters? How would you
	 *	adapt your solution to such case?
	 *=====================================================================
	 */
	bool isAnagram(string s, string t) {
		if (s.empty() && t.empty()) return true;
		if (s.empty() || t.empty()) return false;
		
		std::map<char, int> mp1, mp2;
		countChar(s, mp1);
		countChar(t, mp2);
		
		if (mp1.size() != mp2.size()) return false;
		for (auto it = mp1.begin(); it != mp1.end(); it++) {
			if (mp2.find(it->first) == mp2.end() ||
			    mp2[it->first] != it->second)
			{
				return false;
			}
		}
		return true;
	}

	void countChar(std::string &s, std::map<char, int> &mp) {
		for (int i = 0; i < s.length(); ++i) {
			if (mp.find(s[i]) == mp.end()) {
				mp.insert(std::make_pair(s[i], 0));
			} else {
				++mp[s[i]];
			}
		}
	}

	bool isAnagramProved(std::string s, std::string t) {
		auto cnt = [](std::string& s) -> unordered_map<char, int> {
			unordered_map<char, int> cnt;
			for (auto ch:s) cnt[ch]++;
			return cnt;
		};
        
		return cnt(s) == cnt(t);
	}
};

int main(int argc, const char* argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<std::string> strs;
		while (std::getline(ss, str, ',')) {
			strs.emplace_back(str);
		}
		bool res = Solution().isAnagram(strs[0], strs[1]);

		std::cout << "The given two strings: " << std::endl;
		std::cout << strs[0] << "\n" << strs[1] << std::endl;
		std::cout << "The check result: " << std::endl;
		std::cout << (res ? "True" : "False") << std::endl;
	}
	return 0;
}