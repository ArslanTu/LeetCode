/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
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
    int minimumRecolors(string blocks, int k) {
        int numOfB=0;
        for (int i=0;i<k;++i) {
            if (blocks[i]=='B') ++numOfB;
        }
        int ans=k-numOfB;
        if (ans==0) return ans;
        int cnt=ans;
        for (int i=k;i<blocks.size();++i) {
            if (blocks[i]=='B'&&blocks[i-k]=='W') {
                cnt--;
            } 
            else if (blocks[i]=='W'&&blocks[i-k]=='B') {
                cnt++;
            }
            ans = min(ans,cnt);
        }
        return ans;
    }
};
// @lc code=end

