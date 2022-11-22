/*
 * @lc app=leetcode.cn id=2410 lang=cpp
 *
 * [2410] 运动员和训练师的最大匹配数
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
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i=0,j=0,p=players.size(),t=trainers.size(),ans=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<p&&j<t) {
            if (players[i]<=trainers[j]) {
                ++i;++j;++ans;
            } else {
                ++j;
            }
        }
        return ans;
    }
};
// @lc code=end

