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

class Solution {
public:
	// 39. Combination Sum
	/*=====================================================================
	 * Description: Given a set of candidate numbers without duplicates and
	 *	a target number, find all unique combinations in candidates
	 *	where the candidate numbers sums to target. The same repeated
	 *	number may be chosen from candidates unlimited number of times.
	 * Note:
	 *	All numbers (including target) will be positive integers.
	 *	The solution set must not contain duplicate combinations.
	 * Example:
	 *	Input: candidates = [2,3,6,7], target = 7
	 *	Output: one solution is [[7], [2,2,3]]
	 *	
	 *	Input: candidates = [2,3,5], target = 8
	 *	Output: one solution is [[2,2,2,2], [2,3,3], [3,5]]
	 *=====================================================================
	 */
	std::vector<std::vector<int>> combinationSum(
		std::vector<int>& candidates,
		int target)
	{
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int>> results;
		std::vector<int> result;
		helper(candidates, target, result, results, 0);
		
		return results;
	}
	
	void helper(std::vector<int> &candidates, int target,
		std::vector<int> &result,
		std::vector<std::vector<int>> &results,
		int index)
	{
		if (target <= 0) {
			results.push_back(result);
			return ;
		}
		
		for (int i = index; i < candidates.size(); ++i) {
			if (candidates[i] <= target) {
				result.push_back(candidates[i]);
				helper(candidates, target-candidates[i],
				       result, results, i);
				result.pop_back();
			}
		}
	}

	// 40. Combination Sum II
	/*=====================================================================
	 * Description: Given a collection of candidate numbers and a target
	 *	number,	find all unique combinations in candidates where the
	 *	candidate numbers sums to target. Each number in candidates may
	 *	only be used once in the combination.
	 * Note:
	 *	All numbers (including target) will be positive integers.
	 *	The solution set must not contain duplicate combinations.
	 * Example:
	 *	Input: candidates = [10,1,2,7,6,1,5], target = 8
	 *	Output: one solution is [[1, 7], [1, 2, 5], [2, 6], [1, 1, 6]]
	 *	
	 *	Input: candidates = [2,5,2,1,2], target = 5
	 *	Output: one solution is [[1,2,2], [5]]
	 *=====================================================================
	 */
	std::vector<std::vector<int>> combinationSum2(
		std::vector<int>& candidates,
		int target)
	{
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int>> results;
		std::vector<int> result;
		helper2(candidates, target, result, results, 0);
		
		return results;
	}
	
	void helper2(std::vector<int> &candidates, int target,
		std::vector<int> &result,
		std::vector<std::vector<int>> &results, int index)
	{
		if (target == 0) {
			results.push_back(result);
			return ;
		}
	
		for (int i = index; i < candidates.size(); ++i) {
			if (i > index && candidates[i] == candidates[i-1])
				continue;
			
			if (candidates[i] <= target) {
				result.push_back(candidates[i]);
				helper2(candidates, target-candidates[i],
					result, results, i+1);
				result.pop_back();
			}
		}
	}
};

int main(int argc, const char *argv[]) {
	std::vector<int> candidates1{2, 3, 5};
	std::vector<int> candidates2{10, 1, 2, 7, 6, 1, 5};
	int target = 8;

	Solution solver;
	std::vector<std::vector<int>> results;

	target = solver.combinationSum(candidates1, target);
	std::cout << "original array: " << std::endl;
	for (auto &candidate : candidates1) {
		std::cout << candidate << " ";
	}
	std::cout << std::endl;
	std::cout << "Combination sums: " << std::endl;
	for (int i = 0; i < results.size(); ++i) {
		for (int j = 0; j < results[i].size(); ++j) {
			std::cout << results[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	results = solver.combinationSum2(candidates2, target);
	std::cout << "original array: " << std::endl;
	for (auto &candidate : candidates2) {
		std::cout << candidate << " ";
	}
	std::cout << std::endl;
	std::cout << "Combination sums: " << std::endl;
	for (int i = 0; i < results.size(); ++i) {
		for (int j = 0; j < results[i].size(); ++j) {
			std::cout << results[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

