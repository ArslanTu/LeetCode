/*
 * @lc app=leetcode.cn id=2295 lang=cpp
 *
 * [2295] 替换数组中的元素
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> numToPos;
        int n = nums.size(), m = operations.size();
        for (int i = 0; i < n; ++i) numToPos[nums[i]] = i;
        for (auto& operation : operations) {
            int pos = numToPos[operation[0]];
            numToPos.erase(operation[0]);
            nums[pos] = operation[1];
            numToPos[operation[1]] = pos;
        }
        return nums;
    }
};
// @lc code=end

