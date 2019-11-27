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

class Solution {
public:
	// 28. Implement strStr()
	/* ========================================================================
	 * Description: Implement strStr. Return the index of the first occurrence
	 *	of needle in haystack, or -1 if needle is not part of haystack.
	 *
	 * Example:
	 *	Input: haystack = "hello", needle = "ll"
	 *	Output: 2
	 *
	 *	Input: haystack = "aaaaa", needle = "bba"
	 *	Output: -1
	 *
	 * Clarification: What should we return when needle is an empty string?
	 *	This is a great question to ask during an interview. For the purpose of
	 *	this problem, we will return 0 when needle is an empty string. This is
	 *	consistent to C's strstr() and Java's indexOf().
	 * ========================================================================
	 */
	int strStr(std::string haystack, std::string needle) {
		if (needle.empty()) return 0;
		
		for (int i = 0; i < haystack.length(); ++i) {
			int index = 0;
			if (haystack[i] == needle[index++]) {
				while (index+i < haystack.length() &&
					   index < needle.length() &&
					   haystack[index+i] == needle[index])
				{
					++index;
				}
				if (index == needle.length()) return i;
			}
		}
		
		return -1;
	}

	int strStr2(std::string haystack, std::string needle) {
		if (needle.empty()) return 0;
		if (haystack.empty()) return -1;
		
		int i = 0, j = 0;
		int hsize = haystack.length();
		int nsize = needle.length();
		while (i<hsize && j<nsize) {
			if (haystack[i]==needle[j]) {
				++i; ++j;
			} else {
				if (j > 0) i = i-j+1;
				else ++i;
				j = 0;
			}
		}
		return (j==nsize ? i-j : -1);
	}

	int strStr3(std::string haystack, std::string needle) {
		if(needle.empty()) return 0;
		if(haystack.empty()) return -1;

		int nsize = needle.length();
		std::vector<int> next(nsize, 0);
		
		// Pre-process
		int k = 0;
		for(int i = 1; i < nsize; i++) {
			while(k>0 && needle[k]!=needle[i]) k = next[k-1];
			if(needle[k]==needle[i]) next[i] = ++k;
		}
		k = 0;
		// Matching
		for(int i = 0; i < haystack.size(); i++) {
			while(k>0 && haystack[i]!=needle[k]) k = next[k-1];
			if(haystack[i]==needle[k]) k++;
			if(k==nsize) return i-nsize+1;
		}
		return -1;
	}

	// next数组的含义：当前字符之前的字符串中，有多大长度的相同前缀后缀。
	// 步骤：
	// 	1.首先寻找前缀后缀最长公共元素长度。
	// 	对于P = p0 p1 ...pj-1 pj，寻找模式串P中长度最大且相等的前缀和后缀。
	// 	如果存在p0 p1 ...pk-1 pk = pj- k pj-k+1...pj-1 pj，那么在包含pj
	// 	的模式串中有最大长度为k+1的相同前缀后缀。
	// 	2.将next整体右移一位，第一个元素赋值为-1
	// 	next数组考虑的是除当前字符外的最长相同前缀后缀，所以通过第1步求得各个
	//  前缀后缀的公共元素的最大长度后，只要稍作变形即可。
	void kmp_next(std::string &pattern, std::vector<int> &next) {
		next.resize(pattern.length(), 0);

		next[0] = -1;
		for (int i = 1; i < next.size(); ++i) {
			int tmp = next[i-1];
			while (tmp > 0 && pattern[i-1] != pattern[tmp]) tmp = next[tmp];
			next[i] = ((tmp>=0 && pattern[i-1]==pattern[tmp]) ? tmp+1 : 0);
		}
	}

	// KMP的主要思想：利用已经部分匹配的有效信息，保持i指针不回溯，通过修改j指针，
	// 让模式串尽量地移动到有效的位置。
	int strStr_kmp(std::string haystack, std::string needle) {
		if (needle.empty()) return 0;
		if (haystack.empty()) return -1;

		std::vector<int> next;
		kmp_next(needle, next);
		int i = 0, j = 0;
		int hsize = haystack.length();
		int nsize = needle.length();
		while (i<hsize && j<nsize) {
			if (j==-1 || haystack[i]==needle[j]) { ++i; ++j; }
			else { j = next[j]; }
		}

		return (j==nsize ? i-j : -1);
	}
};

int main(int argc, char const *argv[]) {
	std::string str = "Mississipriver";
	std::string model = "issip";
	Solution solver;
	int res = solver.strStr(str, model);
	std::cout << "The original string:\n" << str << "\n" << model << std::endl;
	std::cout << "The pattern in the string? " << res << std::endl;

	return 0;
}

