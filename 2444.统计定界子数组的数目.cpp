/*
 * @lc app=leetcode.cn id=2444 lang=cpp
 *
 * [2444] 统计定界子数组的数目
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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size(),min_i=-1,max_i=-1,i0=-1;
        for (int i=0;i<n;++i) {
            int x=nums[i];
            if (x==minK) min_i=i;
            if (x==maxK) max_i=i;
            if (x>maxK||x<minK) i0=i;
            ans+=max(0,min(min_i,max_i)-i0);
        }
        return ans;
    }
};
// @lc code=end

