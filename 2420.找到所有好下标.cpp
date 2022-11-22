/*
 * @lc app=leetcode.cn id=2420 lang=cpp
 *
 * [2420] 找到所有好下标
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
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        vector<int> back(n,1);
        vector<int> forward(n,1);
        int pre=INT_MIN;
        for (int i=n-2;i>=k;--i) {
            if (nums[i+1]<=pre) back[i]=back[i+1]+1;
            pre=nums[i+1];
        }
        pre=INT_MIN;
        for (int i=1;i<n-k;++i) {
            if (nums[i-1]<=pre) forward[i]=forward[i-1]+1;
            pre=nums[i-1];
        }
        for (int i=k;i<n-k;++i) {
            if (back[i]>=k&&forward[i]>=k) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

