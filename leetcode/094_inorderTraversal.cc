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
#include <stack>
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
	// 94. Binary Tree Inorder Traversal
	/*=====================================================================
	 * Description: Given a binary tree, return the inorder traversal of
	 *	its nodes' values.
	 *
	 * Example:
	 *	Input: [1,null,2,3]
	 *		1
	 *		 \
	 *		  2
	 *		 /
	 *		3
	 *	Output: [1,3,2]
	 *
	 * Follow up:
	 *	Recursive solution is trivial, could you do it iteratively?
	 *=====================================================================
	 */
	// recursively
	std::vector<int> inorderTraversal(TreeNode* root) {
		std::vector<int> res;
		if (root == nullptr) return res;

		helper(TreeNode* root, res);

		return res;
	}

	void helper(TreeNode* root, std::vector<int> &res) {
		if (root == nullptr) return ;

		if (root->left != nullptr) helper(root->left, res);
		res.push_back(root->val);
		if (root->right != nullptr) helper(root->right, res);
	}

	// iteratively
	std::vector<int> inorderTraversal(TreeNode* root) {
		std::vector<int> res;
		if(nullptr == root) return res;

		std::stack<TreeNode*> s;
		TreeNode* curNode = root;
		while(curNode != nullptr || !s.empty()) {
			while(curNode != nullptr) {
				s.push(curNode);
				curNode = curNode->left;
			}

			curNode = s.top(); s.pop();
			res.push_back(curNode->val);
			curNode = curNode->right;
		}

		return res;
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

std::string integerVectorToString(std::vector<int> list, int length = -1) {
	if (length == -1) length = list.size();
	if (length == 0) return "[]";

	std::string result;
	for(int index = 0; index < length; index++) {
		int number = list[index];
		result += std::to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		std::vector<int> ret = Solution().rightSideView(root);
		std::cout << integerVectorToString(ret) << std::endl;
	}
	return 0;
}