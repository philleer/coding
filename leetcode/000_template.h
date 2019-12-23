/*=============================================================================
 *-----------------------------------------------------------------------------
 * For Array Problems
 *-----------------------------------------------------------------------------
 *=============================================================================
 */

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

class Solution {
public:
	// 121. Best Time to Buy and Sell Stock
	/*=====================================================================
	 * Description: Say you have an array for which the ith element is the
	 *	price of a given stock on day i.
	 *	If you were only permitted to complete at most one transaction
	 *	(i.e., buy one and sell one share of the stock), design an
	 *	algorithm to find the maximum profit.
	 *	Note that you cannot sell a stock before you buy one.
	 *
	 * Example:
	 *	Input: [7,1,5,3,6,4]	Output: 5
	 *	Explanation: Buy on day 2 (price = 1) and sell on day 5
	 *	(price = 6), profit = 6-1 = 5. Not 7-1 = 6, as selling price
	 *	needs to be larger than buying price.
	 *
	 *	Input: [7,6,4,3,1] 	Output: 0
	 *	Explanation: In this case, no transaction is done, i.e. max
	 *	profit = 0.
	 *=====================================================================
	 */
	int maxProfit(std::vector<int>& prices) {
		if (prices.size() < 2) return 0;

		int size = prices.size();
		std::vector<int> dp(size, 0);
		dp[0] = prices[0];
		int maxpro = 0;
		for (int i = 1; i < size; ++i) {
			dp[i] = std::min(dp[i-1], prices[i]);
			maxpro = std::max(prices[i]-dp[i-1], maxpro);
		}

		return maxpro;
	}
};

std::string integerVectorToString(std::vector<std::vector<int>> list,
	int length = -1)
{
	if (length == -1) length = list.size();
	if (length == 0) return "[]";

	std::string result;
	for(int index = 0; index < length; ++index) {
		result += "[";
		for (int j = 0; j < list[index].size()-1; ++j) {
			result += std::to_string(list[index][j]) + ", ";
		}
		result += (std::to_string(list[index].back()) + "], ");
	}
	// -2 的意思是最后一行多了两个字符 ", "
	return "[" + result.substr(0, result.length() - 2) + "]";
}

std::string boolToString(bool input) {
	return input ? "True" : "False";
}

int main(int argc, char const *argv[]) {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<int> prices;
		while (std::getline(ss, str, ' ')) {
			prices.push_back(std::atoi(str.c_str()));
		}

		std::string in = integerVectorToString(prices);
		std::cout << "The given prices are:\n"
			<< in << std::endl;
		int res = Solution().maxProfit(prices);
		std::cout << "The max profit can be gained is : "
			<< res << std::endl;
	}

	return 0;
}



/*=============================================================================
 *-----------------------------------------------------------------------------
 * For Linked List Problems
 *-----------------------------------------------------------------------------
 *=============================================================================
 */

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
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>
// #include <cctype>
// #include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
// 	// 83. Remove Duplicates from Sorted List
// 	/*=====================================================================
// 	 * Description: Given a sorted linked list, delete all duplicates such
// 	 *	that each element appear only once.
// 	 *
// 	 * Example:
// 	 *	Input: 1->1->2		Output: 1->2
// 	 *
// 	 *	Input: 1->1->2->3->3 	Output: 1->2->3
// 	 *=====================================================================
// 	 */
// 	ListNode* deleteDuplicates(ListNode* head) {
// 		ListNode* dummyHead = new ListNode(-1);
// 		dummyHead->next = head;
// 		ListNode* curNode = dummyHead;
// 		while (curNode->next != nullptr) {
// 			ListNode* tmpNode = curNode->next;
// 			if (tmpNode == head) {
// 				curNode = tmpNode;
// 				continue;
// 			}
// 			
// 			if (curNode->val == tmpNode->val) {
// 				curNode->next = tmpNode->next;
// 				delete tmpNode;
// 				tmpNode = nullptr;
// 			} else {
// 				curNode = tmpNode;
// 			}
// 		}
// 
// 		return dummyHead->next;
// 	}
// };

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

std::vector<int> stringToIntegerVector(std::string input) {
	std::vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	char delim = ',';
	while (std::getline(ss, item, delim)) {
		output.push_back(std::stoi(item));
	}
	return output;
}

ListNode* stringToListNode(std::string input) {
	// Generate list from the input
	std::vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for(int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

std::string listNodeToString(ListNode* node) {
	if (node == nullptr) return "[]";

	std::string result;
	while (node) {
		result += std::to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

// std::string boolToString(bool input) {
// 	return input ? "True" : "False";
// }
// 
// int main(int argc, char const *argv[]) {
// 	std::string line;
// 	while (std::getline(std::cin, line)) {
// 		ListNode* head = stringToListNode(line);
// 
// 		ListNode* ret = Solution().deleteDuplicates(head);
// 		std::string out = listNodeToString(ret);
// 		std::cout << out << std::endl;
// 	}
// 
// 	return 0;
// }



/*=============================================================================
 *-----------------------------------------------------------------------------
 * For Binary Tree Problems
 *-----------------------------------------------------------------------------
 *=============================================================================
 */

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
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cctype>
// #include <algorithm>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
// 	// 102. Binary Tree Level Order Traversal
// 	/*=====================================================================
// 	 * Description: Given a binary tree, return the level order traversal
// 	 *	of its nodes' values. (ie, from left to right, level by level).
// 	 *
// 	 * Example:
// 	 *	    3
// 	 *	   / \
// 	 *	  9  20
// 	 *	    /  \
// 	 *	   15   7
// 	 *      Input: [3,9,20,null,null,15,7]
// 	 *	Output: [[3], [9,20], [15,7]]
// 	 *=====================================================================
// 	 */
// 	std::vector<std::vector<int>> levelOrder(TreeNode* root) {
// 		std::vector<std::vector<int>> res;
// 		if (nullptr == root) return res;
// 
// 		std::queue<TreeNode*> q;
// 		q.push(root);
// 		while (!q.empty()) {
// 			int levelNum = q.size();
// 			int levelCnt = 0;
// 			std::vector<int> levelVal;
// 			while (levelCnt++ < levelNum) {
// 				TreeNode* tmpNode = q.front(); q.pop();
// 				levelVal.push_back(tmpNode->val);
// 				if (tmpNode->left != nullptr) q.push(tmpNode->left);
// 				if (tmpNode->right != nullptr) q.push(tmpNode->right);
// 			}
// 			res.push_back(levelVal);            
// 		}
// 
// 		return res;
// 	}
// 
// 	// 103. Binary Tree Zigzag Level Order Traversal
// 	/*=====================================================================
// 	 * Description: Given a binary tree, return the zigzag level order
// 	 *	traversal of its nodes' values. (ie, from left to right, then
// 	 *	right to left for the next level and alternate between).
// 	 *
// 	 * Example:
// 	 *	    3
// 	 *	   / \
// 	 *	  9  20
// 	 *	    /  \
// 	 *	   15   7
// 	 *      Input: [3,9,20,null,null,15,7]
// 	 *	Output: [[3], [20,9], [15,7]]
// 	 *=====================================================================
// 	 */
// 	std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
// 		std::vector<std::vector<int>> res;
// 		if (nullptr == root) return res;
// 
// 		std::queue<TreeNode*> q;
// 		q.push(root);
// 		int levelIndex = 0;
// 		while (!q.empty()) {
// 			++levelIndex;
// 			int levelNum = q.size();
// 			int levelCnt = 0;
// 			std::vector<int> levelVal;
// 			while (levelCnt++ < levelNum) {
// 				TreeNode* tmpNode = q.front(); q.pop();
// 				levelVal.push_back(tmpNode->val);
// 				if (tmpNode->left != nullptr)
// 					q.push(tmpNode->left);
// 				if (tmpNode->right != nullptr)
// 					q.push(tmpNode->right);
// 			}
// 			if ((levelIndex & 1) == 0)
// 				std::reverse(levelVal.begin(), levelVal.end());
// 			res.push_back(levelVal);
// 		}
// 
// 		return res;
// 	}
// };
// 
// // 下面的几个函数均为Leetcode官方测试代码中的实现，用于Debug，非常值得借鉴
// void trimLeftTrailingSpaces(std::string &input) {
// 	input.erase(input.begin(), std::find_if(input.begin(), input.end(),
// 		[](int ch) { return !isspace(ch); }
// 	));
// }
// 
// void trimRightTrailingSpaces(std::string &input) {
// 	input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
// 		return !isspace(ch);
// 	}).base(), input.end());
// }
// 
// TreeNode* stringToTreeNode(std::string input) {
// 	trimLeftTrailingSpaces(input);
// 	trimRightTrailingSpaces(input);
// 	input = input.substr(1, input.length() - 2);
// 	if (!input.size()) return nullptr;
// 
// 	std::string item;
// 	std::stringstream ss;
// 	ss.str(input);
// 	std::getline(ss, item, ',');
// 	TreeNode* root = new TreeNode(std::stoi(item));
// 	std::queue<TreeNode*> nodeQueue;
// 	nodeQueue.push(root);
// 
// 	while (true) {
// 		TreeNode* node = nodeQueue.front();
// 		nodeQueue.pop();
// 
// 		if (!std::getline(ss, item, ',')) break;
// 		trimLeftTrailingSpaces(item);
// 		if (item != "null") {
// 			int leftNumber = std::stoi(item);
// 			node->left = new TreeNode(leftNumber);
// 			nodeQueue.push(node->left);
// 		}
// 
// 		if (!std::getline(ss, item, ',')) break;
// 		trimLeftTrailingSpaces(item);
// 		if (item != "null") {
// 			int rightNumber = std::stoi(item);
// 			node->right = new TreeNode(rightNumber);
// 			nodeQueue.push(node->right);
// 		}
// 	}
// 	return root;
// }
// 
// std::string integerVectorToString(std::vector<std::vector<int>> list, int length = -1) {
// 	if (length == -1) length = list.size();
// 	if (length == 0) return "[]";
// 
// 	std::string result;
// 	for(int index = 0; index < length; ++index) {
// 		result += "[";
// 		for (int j = 0; j < list[index].size()-1; ++j) {
// 			result += std::to_string(list[index][j]) + ", ";
// 		}
// 		result += (std::to_string(list[index].back()) + "], ");
// 	}
// 	// -2 的意思是最后一行多了两个字符 ", "
// 	return "[" + result.substr(0, result.length() - 2) + "]";
// }
// 
// std::string boolToString(bool input) {
// 	return input ? "True" : "False";
// }
// 
// int main(int argc, char const *argv[]) {
// 	std::string line;
// 	while (std::getline(std::cin, line)) {
// 		TreeNode* root = stringToTreeNode(line);
// 		
// 		std::vector<std::vector<int>> ret = Solution().levelOrder(root);
// 		// std::vector<std::vector<int>> ret = Solution().zigzagLevelOrder(root);
// 		std::string out = integerVectorToString(ret);
// 		std::cout << out << std::endl;
// 	}
// 
// 	return 0;
// }

