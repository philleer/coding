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
#include <queue>
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
	// 199. Binary Tree Right Side View
	/*=====================================================================
	 * Description: Given a binary tree, imagine yourself standing on the
	 *	right side of it, return the values of the nodes you can see
	 *	ordered from top to bottom.
	 *
	 * Example:
	 *	Input: [1,2,3,null,5,null,4]	Output: [1, 3, 4]
	 *	Explanation:	
	 *	   1            <---
	 *	 /   \
	 *	2     3         <---
	 *	 \     \
	 *	  5     4       <---
	 *=====================================================================
	 */
	std::vector<int> rightSideView(TreeNode* root) {
		std::vector<int> res;
		if (nullptr == root) return res;

		std::queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			int numNodePerLevel = q.size();
			int numNodeProcessed = 0;
			while (++numNodeProcessed <= numNodePerLevel) {
				TreeNode *tmpNode = q.front(); q.pop();
				if (numNodeProcessed == numNodePerLevel)
					res.push_back(tmpNode->val);
				if (tmpNode->left != nullptr)
					q.push(tmpNode->left);
				if (tmpNode->right != nullptr)
					q.push(tmpNode->right);
			}
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

