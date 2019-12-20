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
        // 46. Permutations
	/*=====================================================================
	 * Description: Given a collection of distinct integers, return all
         *      possible permutations.
         *
	 * Example:
	 *	Input: [1,2,3]
	 *	Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
	 *=====================================================================
	 */
        std::vector<std::vector<int>> permute(std::vector<int> &nums) {
                std::vector<std::vector<int>> res;
                if (nums.empty()) return res;

                int n = nums.size();
                std::vector<int> tmp;
                std::vector<int> flag(n, -1);
                helper(flag, tmp, nums, res);

                return res;
        }
    
        void helper(std::vector<int> &flag, std::vector<int> &tmp,
        	std::vector<int> &nums, std::vector<std::vector<int>> &res) {
                int n = nums.size();
                if (tmp.size() == n) {
                        res.push_back(tmp);
                        return ;
                }

                for (int i = 0; i < n; ++i) {
                        if (flag[i] != 1) {
                                flag[i] = 1;
                                tmp.push_back(nums[i]);
                                helper(flag, tmp, nums, res);
                                flag[i] = 0;
                                tmp.pop_back();
                        }
                }
        }
};

int main(int argc, const char *argv[]) {
	std::vector<int> nums{1, 2, 3};
	
	for (auto &num : nums) std::cout << num << " ";
	std::cout << std::endl;

	std::vector<std::vector<int>> result = Solution().permute(nums);
	std::cout << "The permutations are: "<< std::endl;
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}