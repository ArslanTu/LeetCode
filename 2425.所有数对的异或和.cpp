/*
 * @lc app=leetcode.cn id=2425 lang=cpp
 *
 * [2425] 所有数对的异或和
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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int m=nums1.size();
        int n=nums2.size();
        map<long long,int> mp;
        for (auto elem:nums1) mp[elem]+=n%2;
        for (auto elem:nums2) mp[elem]+=m%2;
        for (auto elem:mp) {
            if (elem.second%2==1) ans^=elem.first;
        }
        return ans;
    }
};
// @lc code=end

