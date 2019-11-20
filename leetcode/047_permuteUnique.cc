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
#include <iostream>     // std::cout, std::endl
#include <sstream>      // std::stringstream
#include <vector>       // std::vector::begin, std::vector::end
#include <string>       // std::getline
#include <algorithm>    // std::sort

class Solution {
public:
        // 47. Permutations II
        /*=====================================================================
         * Description: Given a collection of numbers that might contain
         *      duplicates, return all possible unique permutations.
         *
         * Example:
         *      Input: [1,1,2]  Output: [[1,1,2], [1,2,1], [2,1,1]]
         *=====================================================================
         */
        std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
                std::vector<std::vector<int>> res;
                if (nums.empty()) return res;
                if (nums.size() == 1) {
                    res.push_back(nums);
                    return res;
                }

                std::vector<int> sol;
                std::vector<int> visited(nums.size(), 0);
                std::sort(nums.begin(), nums.end());
                backtrack(nums, res, sol, visited);

                return res;
        }
    
        void backtrack(
                std::vector<int> &nums,
                std::vector<std::vector<int>> &res,
                std::vector<int> &sol,
                std::vector<int> &visited)
        {
                if (sol.size() >= nums.size()) {
                        res.push_back(sol);
                        return ;
                }

                for (int i = 0; i < nums.size(); ++i) {            
                        if (visited[i] == 0) {
                                if (i>0 && nums[i]==nums[i-1] &&
                                    visited[i-1]==0) {
                                        continue;
                                }

                                visited[i] = 1;
                                sol.push_back(nums[i]);
                                backtrack(nums, res, sol, visited);
                                sol.pop_back();
                                visited[i] = 0;
                        }
                }
        }
};

int main(int argc, char *argv[]) {
        std::string line;
        while (std::getline(std::cin, line)) {
                std::stringstream ss;
                ss.str(line);
                int len;
                ss >> len;
                std::vector<int> nums(len, 0);
                std::cout << "Original vector:" << std::endl;
                for (int i = 0; i < len; ++i) {
                        ss >> nums[i];
                        std::cout << nums[i] << " ";
                }
                std::cout << std::endl;

                std::vector<std::vector<int>> res = Solution().permuteUnique();
                std::cout << "Result vector:" << std::endl;
                for (int i = 0; i < res.size(); ++i) {
                        for (int j = 0; j < res[i].size(); ++j) {
                                std::cout << res[i][j] << " ";
                        }
                        std::cout << std::endl;
                }
        }

        return 0;
}
