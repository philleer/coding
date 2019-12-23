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
	// 102. Binary Tree Level Order Traversal
	/*=====================================================================
	 * Description: Given a binary tree, return the level order traversal
	 *	of its nodes' values. (ie, from left to right, level by level).
	 *
	 * Example:
	 *	    3
	 *	   / \
	 *	  9  20
	 *	    /  \
	 *	   15   7
	 *      Input: [3,9,20,null,null,15,7]
	 *	Output: [[3], [9,20], [15,7]]
	 *=====================================================================
	 */
	std::vector<std::vector<int>> levelOrder(TreeNode* root) {
		std::vector<std::vector<int>> res;
		if (nullptr == root) return res;

		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int levelNum = q.size();
			int levelCnt = 0;
			std::vector<int> levelVal;
			while (levelCnt++ < levelNum) {
				TreeNode* tmpNode = q.front(); q.pop();
				levelVal.push_back(tmpNode->val);
				if (tmpNode->left != nullptr) q.push(tmpNode->left);
				if (tmpNode->right != nullptr) q.push(tmpNode->right);
			}
			res.push_back(levelVal);            
		}

		return res;
	}

	// 103. Binary Tree Zigzag Level Order Traversal
	/*=====================================================================
	 * Description: Given a binary tree, return the zigzag level order
	 *	traversal of its nodes' values. (ie, from left to right, then
	 *	right to left for the next level and alternate between).
	 *
	 * Example:
	 *	    3
	 *	   / \
	 *	  9  20
	 *	    /  \
	 *	   15   7
	 *      Input: [3,9,20,null,null,15,7]
	 *	Output: [[3], [20,9], [15,7]]
	 *=====================================================================
	 */
	std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
		std::vector<std::vector<int>> res;
		if (nullptr == root) return res;

		std::queue<TreeNode*> q;
		q.push(root);
		int levelIndex = 0;
		while (!q.empty()) {
			++levelIndex;
			int levelNum = q.size();
			int levelCnt = 0;
			std::vector<int> levelVal;
			while (levelCnt++ < levelNum) {
				TreeNode* tmpNode = q.front(); q.pop();
				levelVal.push_back(tmpNode->val);
				if (tmpNode->left != nullptr)
					q.push(tmpNode->left);
				if (tmpNode->right != nullptr)
					q.push(tmpNode->right);
			}
			if ((levelIndex & 1) == 0)
				std::reverse(levelVal.begin(), levelVal.end());
			res.push_back(levelVal);
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

std::string integerVectorToString(std::vector<std::vector<int>> list, int length = -1) {
	if (length == -1) length = list.size();
	if (length == 0) return "[]";

	std::string result;
	for(int index = 0; index < length; ++index) {
		result += "[";
		for (int & num : list[index]) {
			result += std::to_string(number) + ", ";
		}
		result += "], ";
	}
	// -2 的意思是最后一行多了两个字符 ", "
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		
		std::vector<std::vector<int>> ret = Solution().levelOrder(root);
		// std::vector<std::vector<int>> ret = Solution().zigzagLevelOrder(root);
		std::string out = integerVectorToString(ret);
		std::cout << out << std::endl;
	}

	return 0;
}

