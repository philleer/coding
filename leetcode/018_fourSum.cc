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
#include <sstream>

class Solution {
public:
	// 18. 4Sum
	/*=====================================================================
	 * Description: Given an array nums of n integers and an integer target,
         *      are there elements a, b, c, and d in nums such that a+b+c+d =
         *      target? Find all unique quadruplets in the array which gives
         *      the sum of target.
	 * Note:
         *      The solution set must not contain duplicate quadruplets.
         *
	 * Example:
         *      Input: nums = [1, 0, -1, 0, -2, 2], target = 0.
         *      Output: A solution set is:
         *      [[-1,  0, 0, 1],[-2, -1, 1, 2],[-2,  0, 0, 2]]
	 *=====================================================================
	 */
        std::vector<std::vector<int>> fourSum(std::vector<int>& nums,
                                              int target)
        {
                std::vector<std::vector<int>> res;
                int size = nums.size();
                if (size < 4) return res;
                if (size == 4 && nums[0]+nums[1]+nums[2]+nums[3]==target) {
                        res.push_back(nums);
                        return res;
                }

                std::sort(nums.begin(), nums.end());
                if (nums[0]+nums[1]+nums[2]+nums[3]>target) return res;
                int sum = 0;

                for (int i = 0; i < size-3; ++i) {
                        if (i > 0 && nums[i]==nums[i-1]) continue;
                        for (int j = i+1; j < size-2; ++j) {
                                if (j > i+1 && nums[j]==nums[j-1]) continue;
                                for (int k = j+1; k < size-1; ++k) {
                                        if (k > j+1 && nums[k]==nums[k-1])
                                                continue;
                                        int high = k+1;
                                        while (high < size) {
                                                sum = nums[i] + nums[j] +
                                                      nums[k] + nums[high];
                                                if (sum > target) break;
                                                if (sum < target) ++high;
                                                if (sum == target) {
                                                        std::vector<int> tmp{
                                                                nums[i],
                                                                nums[j],
                                                                nums[k],
                                                                nums[high]};
                                                        res.push_back(tmp);
                                                        break;
                                                }
                                        }
                                }
                        }
                }
                return res;
        }
    
        std::vector<std::vector<int>> fourSumImp(std::vector<int> &nums,
                                                 int target)
        {
                std::vector<std::vector<int>> res;
                int size = nums.size();
                if (size < 4) return res;
                if (size == 4 && nums[0]+nums[1]+nums[2]+nums[3]==target) {
                        res.push_back(nums);
                        return res;
                }
        
                std::sort(nums.begin(), nums.end());
                if (nums[0]+nums[1]+nums[2]+nums[3]>target) return res;
                int sum = 0;
                for (int i = 0; i < size-3; ++i) {
                        if (i > 0 && nums[i]==nums[i-1]) continue;
                                for (int j = i+1; j < size-2; ++j) {
                                if (j > i+1 && nums[j]==nums[j-1])
                                        continue;
                                int low = j+1, high = size-1;
                                while (low < high) {
                                        sum = nums[i] + nums[j] +
                                              nums[low] + nums[high];
                                        if (sum > target)  --high;
                                        if (sum < target) ++low;
                                        if (sum == target) {
                                                std::vector<int> tmp{
                                                        nums[i],
                                                        nums[j],
                                                        nums[low],
                                                        nums[high]};
                                                res.push_back(tmp);
                                                ++low;--high;
                                                while (low < high &&
                                                       nums[low]==nums[low-1])
                                                {
                                                        ++low;
                                                }
                                                while (low < high &&
                                                       nums[high]==nums[high+1])
                                                {
                                                       --high;
                                                }
                                        }
                                }
                        }
                }
                
                return res;
        }
};

int main(int argc, char *argv[]) {
        std::string line;
        while (std::getline(std::cin, line)) {
                std::stringstream ss;
                ss.str(line);
                std::vector<int> nums;
                int tmp;
                while(std::getline(ss, tmp, ',')) {
                        nums.push_back(tmp);
                        std::cout << nums[i] << " ";
                }
                int target = nums.back();
                nums.pop_back();
                std::cout << "\nThe given target is " << target << std::endl;
                
                std::vector<std::vector<int>> res;
                res = Solution().fourSum(nums, target);
                std::cout << "[" << std::endl;
                for (int i = 0; i < res.size(); ++i) {
                        std::cout << "[";
                        for (int j = 0; j < res[i].size(); ++j) {
                                std::cout << res[i][j] << ", ";
                        }
                        std::cout << "]" << std::endl;
                }
                std::cout << "]" << std::endl;
        }
        return 0;
}
