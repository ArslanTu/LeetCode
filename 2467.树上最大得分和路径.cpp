/*
 * @lc app=leetcode.cn id=2467 lang=cpp
 *
 * [2467] 树上最大得分和路径
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

// @lc code=start
class Solution {
private:
    bool findBob(vector<int>& bobInfo, vector<vector<int>>& pic, int cur, int before, int bobTime) {
        if (cur==0) {
            bobInfo[cur]=0;
            return true;
        }
        bool found=false;
        int n=pic.size();
        // 遍历图，找到bob到0的路径
        for (int i = 0; i < pic[cur].size(); ++i) {
            int index=pic[cur][i];
            if (index!=before&&findBob(bobInfo, pic, index, cur, bobTime+1)) {
                found=true;
                break;
            }
        }
        if (found) bobInfo[cur] = bobTime;
        return found;
    }

    void dfs(int cur, int before, int score, int& maxScore, vector<vector<int>>& pic, int aliceTime, vector<int>& bobInfo, vector<int>& amount) {
        if (bobInfo[cur]==aliceTime) {
            score += amount[cur] / 2;
        } else if (bobInfo[cur] > aliceTime) {
            score += amount[cur];
        }
        if (pic[cur].size() == 1) maxScore = max(maxScore, score);
        for (int i = 0; i < pic[cur].size(); ++i) {
            int index = pic[cur][i];
            if (index != before) {
                dfs(index, cur, score, maxScore, pic, aliceTime + 1, bobInfo, amount);
            }
        }
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> pic(amount.size());
        for (auto& edge:edges) {
            pic[edge[0]].push_back(edge[1]);
            pic[edge[1]].push_back(edge[0]);
        }

        vector<int> bobInfo(amount.size(),amount.size());
        findBob(bobInfo, pic, bob, -1, 0);

        pic[0].push_back(-1);
        int ans = INT_MIN;
        dfs(0, -1, 0, ans, pic, 0, bobInfo, amount);
        return ans;
    }
};
// @lc code=end

