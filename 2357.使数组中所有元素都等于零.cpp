/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
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
    int minimumOperations(vector<int>& nums) {
        map<int, int> mp;
        for (auto& num : nums) if (num) mp[num] = 1;
        return mp.size();
    }
};
// @lc code=end

