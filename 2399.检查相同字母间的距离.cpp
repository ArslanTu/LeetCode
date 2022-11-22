/*
 * @lc app=leetcode.cn id=2399 lang=cpp
 *
 * [2399] 检查相同字母间的距离
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
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> last(26,-1);
        int n=s.size();
        for (int i=0;i<n;++i) {
            if (last[s[i]-'a']==-1) last[s[i]-'a']=i;
            else {
                if (i-last[s[i]-'a']-1!=distance[s[i]-'a']) return false;
            }
        }
        return true;
    }
};
// @lc code=end

