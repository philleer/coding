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
#include <algorithm>
#include <unordered_map>

class Solution {
public:
	/*=====================================================================
	 * Description: Given an array of integers, return indices of the two
	 * 	numbers such that they add up to a specific target. You may
	 * 	assume that each input would have exactly one solution, and you
	 * 	may not use the same element twice.			
	 * Example:
	 * 	Input: nums = [2, 7, 11, 15], target = 9
	 * 	Output: [0, 1] 
	 *	Explanatin: since nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
	 *=====================================================================
	 */
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
        	std::unordered_map<int, int> p;
		std::vector<int> res;
        
		for (int i = 0; i < nums.size(); i++) {
			int tem = target - nums[i];
			if (p.count(tem)) {
				res.push_back(p[tem]);
				res.push_back(i);
				break;
			}
			p[nums[i]] = i;
		}

		return res;
	}
};

int main (int argc, const char *argv[]) {
	int nums[4] = {2, 7, 11, 15};
	std::vector<int> vectorTest(4);
	std::copy(nums, nums+4, vectorTest.begin());

	for (int i = 0; i < vectorTest.size(); ++i)
		std::cout << vectorTest[i] << " ";
	std::cout << std::endl;

	std::vector<int> temp = Solution().twoSum(vectorTest, 9);
	for (int j = 0; j < temp.size(); ++j)
		std::cout << temp[j] << " ";
	std::cout << std::endl;

	return 0;
}

