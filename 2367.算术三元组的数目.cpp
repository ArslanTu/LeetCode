/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int,int> mp;
        for (auto& num : nums) mp[num] = 1;
        int ans = 0;
        for (auto& num : nums) if (mp[num + diff] == 1 && mp[num + diff*2] == 1) ++ans;
        return ans;
    }
};
// @lc code=end

