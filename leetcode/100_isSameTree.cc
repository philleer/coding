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
#include <vector>
#include <cctype>
#include <queue>

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
	// 100. Same Tree
	/*=====================================================================
	 * Description: Given two binary trees, write a function to check if
	 *	they are the same or not.
	 *	Two binary trees are considered the same if they are
	 *	structurally identical and the nodes have the same value.
	 *
	 * Example:
	 *         1         1
	 *        / \       / \
	 *       2   3     2   3
	 *	    2
	 *	   / \
	 *	  1   3
	 * 	Input: [1,2,3],   [1,2,3]	Output: true
	 *
	 *         1         1
	 *        /           \
	 *       2             2
	 *	Input: [1,2],     [1,null,2]	Output: false
	 *
	 *         1         1
	 *        / \       / \
	 *       2   1     1   2
	 *	Input: [1,2,1],   [1,1,2] 	Output: false
	 *=====================================================================
	 */
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if (p == nullptr || q == nullptr) return false;

		std::vector<int> valsp;
		std::vector<int> valsq;
		getNode(p, valsp);
		getNode(q, valsq);
		return checkEqual(valsp, valsq);
	}
    
private:
	void getNode(TreeNode* root, std::vector<int> &vals) {
		if (root != nullptr) vals.push_back(root->val);
		else vals.push_back(-1);

		if (root->left != nullptr) getNode(root->left, vals);
		else vals.push_back(-1);

		if (root->right != nullptr) getNode(root->right, vals);
		else vals.push_back(-1);
	}
    
	bool checkEqual(std::vector<int> &vals1, std::vector<int> &vals2) {
		if (vals1.size() != vals2.size()) return false;

		for (int i = 0; i < vals1.size(); ++i) {
			if (vals1[i] != vals2[i])
				return false;
		}
		return true;
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
		TreeNode* root1 = stringToTreeNode(line);

		std::getline(std::cin, line);
		TreeNode* root2 = stringToTreeNode(line);
		
		bool ret = Solution().isSameTree(root1, root2);
		std::string out = boolToString(ret);
		std::cout << out << std::endl;
	}

	return 0;
}

