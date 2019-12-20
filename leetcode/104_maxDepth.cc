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
#include <queue>
#include <pair>
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
	// 104. Maximum Depth of Binary Tree
	/*=====================================================================
	 * Description: Given a binary tree, find its maximum depth.
	 *	The maximum depth is the number of nodes along the longest path
	 *	from the root node down to the farthest leaf node.
	 *
	 * Note:
	 *	A leaf is a node with no children.
	 *
	 * Example:
	 *	Input: [3,9,20,null,null,15,7]
	 *	    3
	 *	   / \
	 *	  9  20
	 *	    /  \
	 *	   15   7
	 *	Output: depth = 3
	 *=====================================================================
	 */
	// Recursively
	int maxDepth(TreeNode* root) {
		if (nullptr == root) return 0;
		int depth = 0;
		helper(root, 1, depth);
		
		return depth;
	}
	
	void helper(TreeNode* root, int depth, int &max_depth) {
		if (nullptr == root) return ;
		if (depth > max_depth) max_depth = depth;
		
		if (root->left != nullptr) {
			helper(root->left, depth+1, max_depth);
		}
		if (root->right != nullptr) {
			helper(root->right, depth+1, max_depth);
		}
	}

	// Iteratively
	int maxDepthIteratively(TreeNode* root) {
		if (nullptr == root) return 0;

		int depth = 1;
		std::queue<std::pair<TreeNode*, int>> q;
		q.push(std::make_pair(root, depth));
		while (!q.empty()) {
			std::pair<TreeNode *, int> tmp = q.front(); q.pop();
			if (tmp.first->left!=nullptr ||
			    tmp.first->right!=nullptr)
			{
				depth = std::max(tmp->second, depth);
			}
			if (tmp.first->left != nullptr)
				q.push(std::make_pair(tmp.first->left,
						      tmp->second+1));
			if (tmp.first->right != nullptr)
				q.push(std::make_pair(tmp.first->right,
						      tmp->second+1));
		}
		
		return depth;
	}
};

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
	TreeNode* root = new TreeNode(stoi(item));
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

int main(int argc, const char* argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		std::cout << Solution().maxDepth(root) << std::endl;
	}
	return 0;
}