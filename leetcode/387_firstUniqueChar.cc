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
#include <pair>

class Solution {
public:
	// 387. First Unique Character in a String
	/*=====================================================================
	 * Description: Given a string, find the first non-repeating character
	 *	in it and return it's index. If it doesn't exist, return -1.
	 *
	 * Example:
	 *	Input: s = "leetcode"	Output: 0
	 *
	 *	Input: s = "loveleetcode"	Output: 2
	 *
	 * Note:
	 * 	You may assume the string contain only lowercase letters.
	 *=====================================================================
	 */
	int firstUniqChar(std::string s) {
		int len = s.length();
		if (len == 1) return 0;
		if (len == 0) return -1;

		std::unordered_map<char, std::pair<int, int>> mp;
		for (int i = 0; i < len; ++i) {
			if (mp.find(s[i]) == mp.end()) {
				mp.insert(std::make_pair(s[i],
					  std::make_pair(i, 0)));
			} else {
				++(mp[s[i]].second);
			}
		}

		int index = 65536;
		for (auto it = mp.begin(); it != mp.end(); ++it) {			
			if ((it->second).second == 0 &&
			    (it->second).first < index)
			{
				index = (it->second).first;
			}
		}

		return (index < 65536 ? index : -1);
	}
};

std::string stringToString(std::string input) {
	assert(input.length() >= 2);
	std::string result;
	for (int i = 1; i < input.length() -1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i+1];
			switch (nextChar) {
				case '\"': result.push_back('\"'); break;
				case '/' : result.push_back('/'); break;
				case '\\': result.push_back('\\'); break;
				case 'b' : result.push_back('\b'); break;
				case 'f' : result.push_back('\f'); break;
				case 'r' : result.push_back('\r'); break;
				case 'n' : result.push_back('\n'); break;
				case 't' : result.push_back('\t'); break;
				default: break;
			}
			++i;
		} else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main(int argc, const char* argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string s = stringToString(line);
		std::cout << Solution().firstUniqChar(s) << std::endl;
	}
	return 0;
}