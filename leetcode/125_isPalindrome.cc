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
#include <assert.h>

class Solution {
public:
        // 125. Valid Palindrome
        /*====================================================================
         * Description: Given a string, determine if it is a palindrome,
         *      considering only alphanumeric characters and ignoring cases.
         * Note:
         *      For the purpose of this problem, we define empty string as
         *      valid palindrome.
         *
         * Example:
         *      Input: "A man, a plan, a canal: Panama" Output: true
         *
         *      Input: "race a car"     Output: false
         *====================================================================
         */
        bool isPalindrome(std::string s) {
                if (s.empty()) return true;
                
                std::string str;
                to_lower(s, str);
                std::cout << str << std::endl;
                int low = 0;
                int high = str.length()-1;
                while (low < high) {
                    if (str[low]==str[high]) {
                        ++low;
                        --high;
                    } else {
                        return false;
                    }
                }
                
                return true;
        }
    
        void to_lower(std::string &s, std::string &res) {
                for (int i = 0; i < s.length(); ++i) {
                        if (s[i] >= 'A' && s[i] <= 'Z') {
                                res += (s[i]+32);
                        }
                        if ((s[i] >= 'a' && s[i] <= 'z') ||
                            (s[i] >= '0' && s[i] <= '9'))
                        {
                                res += s[i];
                        }
                }
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
                        i++;
                } else {
                        result.push_back(currentChar);
                }
        }
        return result;
}

std::string boolToString(bool input) {
        return input ? "True" : "False";
}

int main(int argc, char *argv[]) {
        std::string line;
        while (std::getline(std::cin, line)) {
                std::string s = stringToString(line);

                bool ret = Solution().isPalindrome(s);
                std::string out = boolToString(ret);
                std::cout << out << std::endl;
        }
        return 0;
}
