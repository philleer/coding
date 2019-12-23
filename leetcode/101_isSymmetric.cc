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
#include <algorithm>
#include <queue>
#include <cctype>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 101. Symmetric Tree
	/*=====================================================================
	 * Description: Given a binary tree, check whether it is a mirror of
	 *	itself (ie, symmetric around its center).
	 *
	 * Example:
	 *	    1
	 *	   / \
	 *	  2   2
	 *	 / \ / \
	 *	3  4 4  3
	 *      Input: [1,2,2,3,4,4,3]	Output: true
	 *
	 *	    1
	 *	   / \
	 *	  2   2
	 *	   \   \
	 *	   3    3
	 *	Input: [1,2,2,null,3,null,3]	Output: false
	 *
	 * Note:
	 *	Bonus points if you could solve it both recursively and
	 *	iteratively.
	 *=====================================================================
	 */
	bool isSymmetric(TreeNode* root) {
		if (nullptr == root) return true;

		return helper(root->left, root->right);
	}
    
private:
	bool helper(TreeNode* left, TreeNode* right) {
		if (nullptr == left && nullptr == right) return true;
		if (nullptr == left || nullptr == right) return false;

		if (left->val != right->val) return false;

		return (helper(left->left, right->right) &&
			helper(left->right, right->left));
	}
};

// 下面的几个函数均为Leetcode官方测试代码中的实现，用于Debug，非常值得借鉴
void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), std::find_if(input.begin(), input.end(),
		[](int ch) { return !isspace(ch); }
	));
}

void trimRightTrailingSpaces(std::string &input) {
	input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode* stringToTreeNode(std::string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) return nullptr;

	std::string item;
	std::stringstream ss;
	ss.str(input);
	std::getline(ss, item, ',');
	TreeNode* root = new TreeNode(std::stoi(item));
	std::queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!std::getline(ss, item, ',')) break;
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = std::stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!std::getline(ss, item, ',')) break;
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = std::stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

std::string boolToString(bool input) {
	return input ? "True" : "False";
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		
		bool ret = Solution().isSymmetric(root);
		std::string out = boolToString(ret);
		std::cout << out << std::endl;
	}

	return 0;
}

