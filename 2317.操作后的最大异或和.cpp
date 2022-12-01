/*
 * @lc app=leetcode.cn id=2317 lang=cpp
 *
 * [2317] 操作后的最大异或和
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
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (auto& num : nums) ans |= num;
        return ans;
    }
};
// @lc code=end

