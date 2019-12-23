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
#include <algorithm>

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
	// 98. Validate Binary Search Tree
	/*=====================================================================
	 * Description: Given a binary tree, determine if it is a valid binary
	 *	search tree (BST).
	 * 	Assume a BST is defined as follows:
	 *	- The left subtree of a node contains only nodes with keys less
	 *	  than the node's key.
	 *	- The right subtree of a node contains only nodes with keys
	 *	  greater than the node's key.
	 *	- Both the left and right subtrees must also be binary search
	 *	  trees.
	 *
	 * Example:
	 *	    2
	 *	   / \
	 *	  1   3
	 * 	Input: nums = [2,1,3]	Output: true
	 *
	 *	    5
	 *	   / \
	 *	  1   4
	 *	     / \
	 *	    3   6
	 *	Input: [5,1,4,null,null,3,6]	Output: false
	 *	Explanation: The root node's value is 5 but its right child's
	 *	value is 4.
	 *=====================================================================
	 */
	bool isValidBST(TreeNode* root) {
		if (nullptr == root) return true;

		// The first method
		return helper(root, nullptr, nullptr);

		// The second method
		// std::vector<int> values;
		// inorder(root, values);
		// for (int i = 1; i < values.size(); ++i) {
		// 	if (values[i] <= values[i-1]) {
		// 		return false;
		// 	}
		// }
		// return true;
	}
    
private:
	bool helper(TreeNode* root, TreeNode* max, TreeNode* min) {
		if (nullptr == root) return true;

		if (max != nullptr && root->val >= max->val) return false;
		if (min != nullptr && root->val <= min->val) return false;

		return (helper(root->left, root, min) && helper(root->right, max, root));
	}
    
	void inorder(TreeNode* root, std::vector<int> &values) {
		if (nullptr == root) return ;
		inorder(root->left, values);
		values.push_back(root->val);
		inorder(root->right, values);
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
		std::vector<int> ret = Solution().isValidBST(root);
		bool sym = integerVectorToString(ret);
		std::cout << (sym ? "True" : "False") << std::endl;
	}

	return 0;
}

