/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
#include <vector>
#include <map>
#include <algorithm>
using std::vector;
using std::map;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res=0;
        long long temp=0;
        int count=0;
        vector<int> last(100005,-k);
        for (int i=0;i<nums.size();++i) {
            if (last[nums[i]]!=i&&last[nums[i]]>i-k) {
                int newPos=last[nums[i]]+1;
                last[nums[i]]=i;
                i=newPos;
                temp=0;
                count=0;
            } else last[nums[i]]=i;
            temp+=nums[i];
            ++count;
            if (count==k) {
                res=temp>res?temp:res;
                temp-=nums[i-k+1];
                --count;
            }
        }
        return res;
    }
};
// @lc code=end

