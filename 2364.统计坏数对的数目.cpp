/*
 * @lc app=leetcode.cn id=2364 lang=cpp
 *
 * [2364] 统计坏数对的数目
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] - i;
        }
        map<int,long long> mp;
        for (auto& num : nums) mp[num]++;
        long long ans = (n * (n - 1))/2;
        for (auto& elem : mp) if (elem.second > 1) ans -= (elem.second - 1)*elem.second/2;
        return ans;
    }
};
// @lc code=end

