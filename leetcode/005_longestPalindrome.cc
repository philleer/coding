// This file is part of my coding practice, a lightweight C++
// solution for newcoder program practice.
//
// For all of files in the coding folder, I check the rightness
// not only by the case test online, but also by my offline IDE
// Microsoft Visual Studio 2010 as well when I write on windows
// 7 64-bit platform or by g++5.4 when I am on linux platform.
// 
// If there are some questions, please send me an email: 
// Phil <phillee2016@163.com> or feel free to create an issue.

#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    /*
     * Description:	Given a string s, find the longest palindromic
     * 				substring in s. You may assume that the maximum
     * 				length of s is 1000.
     * Example 1:	Input: "babad"	Output: "bab"
     * 				Note: "aba" is also a valid answer.
     * Example 2:	Input: "cbbd"	Output: "bb"
     */	
    string longestPalindrome(string s) {
        string res;
        if (s.empty())
            return res;
        
        int len = s.length();
        int tmpLen = 0, maxLen = 0;
        int start = 0;
        
        // for palindrome like abba
        for (int ii = 0; ii < len; ii++) {
            tmpLen = 0;
            for (int jj = 0; (jj <= ii) && (jj < (len - ii - 1)); jj++) {
                if (s[ii - jj] == s[ii + 1 + jj]) {
                    tmpLen = jj * 2 + 2;
                    if (tmpLen > maxLen) {
                        maxLen = tmpLen;
                        start = ii - jj;
                    }
                }
                else {
                    break;
                }
            }
        }
        
        // for palindrome like bab
        for (int i = 1; i < len - 1; i++) {
            tmpLen = 0;
            for (int j = 1; (j <= i) && (j < len - i); j++) {
                if (s[i - j] == s[i + j]) {
                    tmpLen = j * 2 + 1;
                    if (tmpLen > maxLen) {
                        maxLen = tmpLen;
                        start = i - j;
                    }
                }
                else {
                    break;
                }
            }
        }
        
        res = s.substr(start, maxLen);
        // if there is no palindrome existing in the given string
        // then return the first character of s
        if (res.empty())
            res = s.substr(0, 1);
            
        return res;
    }
};

int main(int argc, char **argv) {
	string str1 = "babad";
	string str2 = "cbbd";
	string str3 = "abcda";
	string str4 = "";
	printf("the given string is shown as:\n");
	printf("\tstr1 = %s\n", str1.c_str());
	printf("\tstr2 = %s\n", str2.c_str());
	printf("\tstr3 = %s\n", str3.c_str());
	printf("\tstr4 = %s\n", str4.c_str());

	Solution solver;
    string result = solver.longestPalindrome(str1);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

	result = solver.longestPalindrome(str2);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

	result = solver.longestPalindrome(str3);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

	result = solver.longestPalindrome(str4);
	printf("\nthe result substring is shown as:\n");
	printf("\tresult = %s", result.c_str());

    return 0;
}