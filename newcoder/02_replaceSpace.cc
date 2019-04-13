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

#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
	/*=============================================================
	 * 题目描述：实现一个函数，将一个字符串中的空格替换成“%20”
	 * 例如：	输入字符串We are happy
	 *			经过替换后的字符串为We%20are%20happy
	 * 注意：	测试过程中要保证输入的字符串足以容纳替换后的字符串
	 *=============================================================
	 */
	void replaceSpace(char *str,int length) {
        if (str == nullptr)
            return;
        int countBlank = 0;
        for (int i = 0; i < length; i++)
        	// 首先统计字符串中空格数量
            if (str[i] == ' ')
                countBlank++;
        for (int i = length - 1; i >= 0; i--) {
            if (str[i] != ' ')
                str[i+2*countBlank] = str[i];
            else {
                str[i+2*countBlank] = '0';
                str[i+2*countBlank-1] = '2';
                str[i+2*countBlank-2] = '%';
                countBlank--;
            }
        }
	}
};

int main(int argc, char **argv) {
	char stringTest[20] = "We are happy";
	int lengthOfString = 12;
	Solution solver;

	printf("Before modify: %s\n", stringTest);

	solver.replaceSpace(stringTest, lengthOfString);
	
	printf("After modify: %s\n", stringTest);
	return 0;
}