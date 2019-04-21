#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

class Solution
{
public:
	/*=============================================================
	 * 题目描述: 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
	 *			假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	 * 例如: 	输入前序遍历{1,2,4,7,3,5,6,8},中序遍历{4,7,2,1,5,3,8,6}
	 *			重建二叉树并返回
	 *=============================================================
	 */
	TreeNode* constructTree(vector<int> &pre, vector<int> &vin) {
		if (pre.empty() || vin.empty())
			return nullptr;

		return constructCore(pre, pre+pre.size()-1, vin, vin+vin.size()-1);
	}

	TreeNode* constructCore(int *startpre, int *endpre, int *startvin, int *endvin) {
		TreeNode *root = new TreeNode(*startpre);

		if (startpre == endpre && *startpre == *endpre) {
			if (startvin == endvin && *startvin == *endvin)
				return root;
		}

		int *rootvin = startvin;
		while (rootvin <= endvin && *rootvin != *startpre)
			rootvin++;

		int leftLength = rootvin - startvin;
		int rightLength = endvin - rootvin;
		if (leftLength > 0) {
			root->left = constructCore(startpre+1, startpre+leftLength, 
				startvin, rootvin-1);
		}
		if (rightLength > 0) {
			root->right = constructCore(startpre+leftLength+1, endpre, 
				rootvin+1, endvin);
		}
		return root;
	}

	// 二叉树的前序遍历
	vector<int> preorderTraverse(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;		
		
		stack<TreeNode*> stackTree;
		TreeNode* pNode = root;
		while (pNode != nullptr || !stackTree.empty()) {
			if (pNode != nullptr) {
				res.push_back(pNode->val);
				stackTree.push(pNode);
				pNode = pNode->left;
			}
			else {
				pNode = stackTree.top()->right;
				stackTree.pop();
			}
		}
		return res;
	}

	// 二叉树的中序遍历
	vector<int> inorderTraverse(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;

		stack<TreeNode*> stackTree;
		TreeNode* pNode = root;
		while (pNode != nullptr || !stackTree.empty()) {
			if (pNode != nullptr) {
				stackTree.push(pNode);
				pNode = pNode->left;
			}
			else {
				pNode = stackTree.top();
				res.push_back(pNode->val);
				pNode = pNode->right;
				stackTree.pop();
			}
		}

		return res;
	}

	// 二叉树的后序遍历
	vector<int> postorderTraverse(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;

		stack<TreeNode*> stackTree;
		stackTree.push(root);
		TreeNode* preNode = nullptr;
		TreeNode* curNode = nullptr;

		while (!stackTree.empty()) {
			curNode = stackTree.top();
			if ((curNode->left == nullptr && curNode->right == nullptr) ||
				(preNode != nullptr &&
				(preNode == curNode->left || preNode == curNode->right))) {
				res.push_back(curNode->val);
				stackTree.pop();
				preNode = curNode;
			}
			else {
				if (curNode->left != nullptr)
					stackTree.push(curNode->left);
				if (curNode->right != nullptr)
					stackTree.push(curNode->right);
			}
		}
		return res;
	}

	/*
	 * 描述：直接打印二叉树各结点的值
	 * 输入：二叉树根结点地址
	 * 输出：一个包含各节点值得vector
	 */
	void printTree(TreeNode* root) {
		if (root == nullptr)
			return ;
		
		TreeNode* pNode = root;
		queue<TreeNode*> q;
		q.push(pNode);
		
		printf("Tree node value:\n\t");
		while (!q.empty()) {
			pNode = q.front();
			printf("%d\t", pNode->val);
			if (pNode->left != nullptr)
				q.push(pNode->left);
			if (pNode->right != nullptr)
				q.push(pNode->right);
			q.pop();
		}

		printf("\n");
	}

	/*
	 * 描述：将二叉树中各结点的值分层保存，非递归做法（阿里实习生面试题）
	 * 输入：二叉树根结点地址
	 * 输出：每一层的值包含在一个vector中，作为整体vector的一个元素
	 */
	vector<vector<int> > Solution::levelOrder(TreeNode* root) {
		vector<vector<int> > res;
		if (root == nullptr) return res;

		TreeNode* pNode = root;
		queue<TreeNode *> q;
		q.push(pNode);
		
		while (!q.empty())
		{
			vector<int> level;
			int numNodeGo = 0;
			int numNodeLevel = q.size();
			while (numNodeGo++ < numNodeLevel)
			{
				pNode = q.front();
				level.push_back(pNode->val);
				if (pNode->left != nullptr)
					q.push(pNode->left);
				if(pNode->right != nullptr)
					q.push(pNode->right);
				q.pop();
			}
			res.push_back(level);
		}
		return res;
	}

public:
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int value):val(value), left(nullptr), right(nullptr){}
	};
}

int main(int argc, char** argv) {

	int preList[8] = {1,2,4,7,3,5,6,8};
	vector<int> preOrderList;
	preOrderList.assign(preList, preList+8);

	int inList[8] = {4,7,2,1,5,3,8,6};
	vector<int> inOrderList;
	inOrderList.assign(inList, inList+8);

	Solution solver;
	// 根据输入的前序遍历序列和中序遍历序列重建二叉树
	TreeNode* result = solver.constructTree(preOrderList, inOrderList);
	
	// 将重建的二叉树打印出来检验正确性
	solver.printTree(result);

	// 分层打印二叉树
	vector<vector<int> > res = solver.levelOrder(result);
	for (int i = 0; i < res.size(); i++) {
		printf("level %d:\t", i);
		for (int j = 0; j < res[i].size(); j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}

	// 根据重建的二叉树进行前序遍历并打印结果
	vector<int> preorderList = solver.preorderTraverse(result);
	printf("preorder traverse:\n\t");
	for (int i = 0; i < preorderList.size(); i++)
		printf("%d ", preorderList[i]);
	printf("\n");

	// 根据重建的二叉树进行中序遍历并打印结果
	vector<int> inorderList = solver.inorderTraverse(result);
	printf("inorder traverse:\n\t");
	for (int i = 0; i < inorderList.size(); i++)
		printf("%d ", inorderList[i]);
	printf("\n");

	// 根据重建的二叉树进行后序遍历并打印结果
	vector<int> postorderList = solver.postorderTraverse(result);
	printf("postorder traverse:\n\t");
	for (int i = 0; i < postorderList.size(); i++)
		printf("%d ", postorderList[i]);
	printf("\n");

	return 0;
}