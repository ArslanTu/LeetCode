/*
 * @lc app=leetcode.cn id=2433 lang=cpp
 *
 * [2433] 找出前缀异或的原始数组
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
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
        ans[0]=pref[0];
        for (int i=1;i<pref.size();++i) ans[i]=pref[i]^pref[i-1];
        return ans;
    }
};
// @lc code=end

