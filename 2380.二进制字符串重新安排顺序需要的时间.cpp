/*
 * @lc app=leetcode.cn id=2380 lang=cpp
 *
 * [2380] 二进制字符串重新安排顺序需要的时间
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
    int secondsToRemoveOccurrences(string s) {
        int ans=0;
        for (int cnt=0,i=0;i<s.size();++i) {
            if (s[i]=='0') ++cnt;
            else if (cnt>0) ans=max(ans+1,cnt);
        }
        return ans;
    }
};
// @lc code=end

