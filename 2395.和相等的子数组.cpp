/*
 * @lc app=leetcode.cn id=2395 lang=cpp
 *
 * [2395] 和相等的子数组
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for (int i=1;i<n;++i) {
            if (mp[nums[i]+nums[i-1]]==1) return true;
            else mp[nums[i]+nums[i-1]]=1;
        }
        return false;
    }
};
// @lc code=end

