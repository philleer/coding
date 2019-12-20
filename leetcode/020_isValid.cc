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
#include <stack>

class Solution {
public:
	// 20. Valid Parentheses
	/*=====================================================================
	 * Description: Given a string containing just the characters'(', ')',
	 * 	'{', '}', '[' and ']', determine if the input string is valid.
	 *	An input string is valid if:
	 *	Open brackets must be closed by the same type of brackets.
	 *	Open brackets must be closed in the correct order.
	 *	Note that an empty string is also considered valid.
	 * Example:
	 * 	Input: "()"		Output: true
	 * 	Input: "()[]{}"	Output: true
	 * 	Input: "(]"		Output: false
	 * 	Input: "([)]"	Output: false
	 * 	Input: "{[]}"	Output: true
	 *======================================================================
	 */
	bool isValid(std::string s) {
		std::stack<char> st;

		for (int i = 0; i < s.length(); i++) {
			if (!st.empty() && ((st.top() == '(' && s[i] == ')') ||
				(st.top() == '[' && s[i] == ']') ||
				(st.top() == '{' && s[i] == '}'))) {
				st.pop();
			} else {
				if (!st.empty() &&
				    (
				     (st.top() == '(' &&
				      (s[i] == ']' || s[i] == '}')) ||
				     (st.top() == '[' &&
				      (s[i] == ')' || s[i] == '}')) ||
				     (st.top() == '{' &&
				      (s[i] == ']' || s[i] == ')'))
				    )
				   )
					return false;
				else
					st.push(s[i]);
			}
		}

		return st.empty();
	}
};

int main(int argc, char const* argv[]) {
	std::string s1 = "()[]{}";
	Solution solver;
	
	std::cout << s1 << " " << (solver.isValid(s1)) ? "true" : "false"
		<< std::endl;
	s1 = "(]";
	std::cout << s1 << " " << (solver.isValid(s1)) ? "true" : "false"
		<< std::endl;

	return 0;
}

