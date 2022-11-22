/*
 * @lc app=leetcode.cn id=2414 lang=cpp
 *
 * [2414] 最长的字母序连续子字符串的长度
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
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int ans=1;
        int cnt=1;
        for (int i=1;i<n;++i) {
            if (s[i]-s[i-1]==1) {
                cnt++;
                ans=cnt>ans?cnt:ans;
            }
            else cnt=1;
        }
        return ans;
    }
};
// @lc code=end

