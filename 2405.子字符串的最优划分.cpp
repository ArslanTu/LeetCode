/*
 * @lc app=leetcode.cn id=2405 lang=cpp
 *
 * [2405] 子字符串的最优划分
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
    int partitionString(string s) {
        int n=s.size();
        vector<int> last(26,-1);
        vector<int> temp(26,-1);
        int ans=0;
        for (int i=0;i<n;++i) {
            if (last[s[i]-'a']==-1) last[s[i]-'a']=i;
            else {
                ans++;
                last=temp;
                --i;
            }
        }
        return ans+1;
    }
};
// @lc code=end

