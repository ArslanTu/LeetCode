/*
 * @lc app=leetcode.cn id=2434 lang=cpp
 *
 * [2434] 使用机器人打印字典序最小的字符串
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
    string robotWithString(string s) {
        string ans="";
        vector<int> count(26,0);
        for (auto c:s) ++count[c-'a'];
        int min=0;
        stack<char> st;
        for (int i=0;i<s.size();++i) {
            count[s[i]-'a']--;
            while (min<25&&count[min]==0) ++min;
            st.push(s[i]);
            while (!st.empty()&&st.top()-'a'<=min) {
                ans+=st.top();
                st.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

