/*
 * @lc app=leetcode.cn id=2437 lang=cpp
 *
 * [2437] 有效时间的数目
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
    int countTime(string time) {
        int ans=1;
        if (time[0]=='?'&&time[1]=='?') {
            ans*=24;
        } else if (time[0]=='?'&&int(time[1])-48<=3) ans*=3;
        else if (time[0]=='?'&&int(time[1])-48>3) ans*=2;
        else if (time[0]=='2'&&time[1]=='?') ans*=4;
        else if ((time[0]=='0'||time[0]=='1')&&time[1]=='?') ans*=10;

        if (time[3]=='?') ans*=6;
        if (time[4]=='?') ans*=10;
        return ans;
    }
};
// @lc code=end

