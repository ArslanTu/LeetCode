/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <map>
#include <vector>
using std::vector;
using std::map;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        for(int e:nums1)
        {
            m[e]=1;
        }
        for(int e:nums2)
        {
            if(m[e]==1) m[e]+=1;
        }
        vector<int> res;
        for(auto p:m)
        {
            if(p.second>1) res.push_back(p.first);
        }
        return res;
    }
};
// @lc code=end

