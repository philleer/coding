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
#include <queue>

class Solution {
public:
	struct TreeNode {
	public:
	    TreeNode* left;
	    TreeNode* right;
	    int val;
	    TreeNode(int _val) : left(nullptr), right(nullptr), val(_val) {}
	};

public:
	/* ========================================================================
	 * 功能描述：给定一个二叉树，要求按行打印出树结构
	 * 示例：输入：
	 *	第一行         9
	 *	第二行    8         7
	 *      第三行 6     4   5     3
	 *	第四行  12  1 0         2
	 *  输出：[[9],[8,7],[6,4,5,3],[12,1,0,2]]
	 * ========================================================================
	 */
	// 使用队列，记录每行结点的个数
	std::vector<std::vector<int>> treeByLevel(TreeNode *root) {
 	    std::vector<std::vector<int>> res;
   	    if (root == nullptr) return res;
 	   
 	    TreeNode *currentNode = root;
 	    std::queue<TreeNode*> q;
 	    q.push(currentNode);
 	    while (!q.empty()) {
 	   	int nodeNumPerLevel = q.size();
 	   	int nodeNumProcessedPerLevel = 0;
 	   	std::vector<int> curLevelValues;
 	   	while (nodeNumProcessedPerLevel < nodeNumPerLevel) {
 	   	    currentNode = q.front(); q.pop();
 	   	    curLevelValues.push_back(currentNode->val);
 	   	    if (currentNode->left != nullptr) q.push(currentNode->left);
 	   	    if (currentNode->right != nullptr) q.push(currentNode->right);
 	   	    ++nodeNumProcessedPerLevel;
 	   	}
 	   
		res.push_back(curLevelValues);
	    }

	    return res;
	}

	// 利用树的结构相似性，递归保存结点的值
	std::vector<std::vector<int>> treeByLevelRecursively(TreeNode *root) {
	    std::vector<std::vector<int>> res;
	    if (root == nullptr) return res;

	    recursiveLevel(root, res, 0);
	    return res;
	}
	void recursiveLevel(TreeNode *root, std::vector<std::vector<int>> &result, int level) {
	    if (level < result.size()) {
	    	result[level].push_back(root->val);
	    } else {
	    	std::vector<int> curLevelValues;
	    	curLevelValues.push_back(root->val);
	    	result.push_back(curLevelValues);
	    }

	    if (root->left != nullptr) recursiveLevel(root->left, result, level+1);
	    if (root->right != nullptr) recursiveLevel(root->right, result, level+1);
	}

	TreeNode *constructTree(std::vector<int> &vin) {
	    if (vin.empty()) return nullptr;

	    TreeNode *root = new TreeNode(vin[0]);
	    TreeNode *pNode = root;
	    int size = vin.size();
	    std::queue<TreeNode*> q;
	    q.push(pNode);
	    for (int i = 0; i < size/2; ++i) {
	    	TreeNode *curNode = q.front(); q.pop();
	    	int tmp = 2*i+1;
	    	if (tmp < size && vin[tmp] != -1) {
    		    curNode->left = new TreeNode(vin[tmp]);
	    	    q.push(curNode->left);
	    	}
	    	++tmp;
	    	if (tmp < size && vin[tmp] != -1) {
	    	    curNode->right = new TreeNode(vin[tmp]);
	    	    q.push(curNode->right);
	    	}
	    }
	    return root;
	}
};

int main(int argc, char const *argv[]) {
	std::vector<int> nums{9,8,7,6,4,5,3,-1,12,1,0,-1,-1,-1,2};
	TreeNode *root = constructTree(nums);
	Solution solver;
	std::vector<std::vector<int>> result = solver.treeByLevel(root);
	printf("Print node value in level order:\n");
	for (int i = 0; i < result.size(); ++i) {
		for (auto &val : result[i]) {
			printf("%d ", val);
		}
		printf("\n");
	}

	return 0;
}

