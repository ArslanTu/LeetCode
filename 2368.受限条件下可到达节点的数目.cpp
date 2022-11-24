/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 *
 * [2368] 受限条件下可到达节点的数目
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
    int ans=0;
    void dfs(vector<vector<int>>& pic, int cur, int before, map<int,int>& mp) {
        // 受限则直接返回
        if (mp[cur] == 1) return;
        // 不受限，说明可达，计数加一
        ++ans;
        // 如果是叶子结点，返回
        if (pic[cur].size() == 1) return;
        else {
            // 非叶子结点，遍历连接的其他结点
            for (int i = 0; i < pic[cur].size(); ++i) {
                int index = pic[cur][i];
                if (index != before) dfs(pic, index, cur, mp);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // 建图
        vector<vector<int>> pic(n);
        for (auto& edge : edges) {
            pic[edge[0]].push_back(edge[1]);
            pic[edge[1]].push_back(edge[0]);
        }
        // 将受限结点存入map，便于查询
        map<int,int> mp;
        for (auto& elem : restricted) mp[elem] = 1;
        // 防止首结点被识别为叶子
        pic[0].push_back(-1);
        ans = 0;
        dfs(pic, 0, -1, mp);
        return ans;
    }
};
// @lc code=end

