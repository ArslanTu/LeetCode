/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 *
 * [2359] 找到离给定两个节点最近的节点
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
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // 原创
        // int n = edges.size();

        // vector<int> seq1;
        // map<int,int> nodes1;
        // int cur = node1;
        // while (true) {
        //     if (nodes1[cur] !=0 ) break;
        //     else {
        //         nodes1[cur] = 1;
        //         seq1.push_back(cur);
        //     }
        //     if (edges[cur] == -1) break;
        //     else cur = edges[cur];
        // }
        // vector<int> seq2;
        // map<int,int> nodes2;
        // cur = node2;
        // while (true) {
        //     if (nodes2[cur] !=0 ) break;
        //     else {
        //         nodes2[cur] = 1;
        //         seq2.push_back(cur);
        //     }
        //     if (edges[cur] == -1) break;
        //     else cur = edges[cur];
        // }
        // int ans = INT_MAX;
        // int len = INT_MAX;
        // int a = seq1.size(), b = seq2.size();
        // vector<int> node1Time(n, -1);
        // for (int i = 0; i < a; ++i) {
        //     node1Time[seq1[i]] = i;
        // }
        // vector<int> node2Time(n, -1);
        // for (int i = 0; i < b; ++i) {
        //     node2Time[seq2[i]] = i;
        // }

        // for (int i = 0; i < n; ++i) {
        //     if (node1Time[i] != -1 && node2Time[i] != -1) {
        //         if (max(node1Time[i], node2Time[i]) < len) {
        //             len = max(node1Time[i], node2Time[i]);
        //             ans = i;
        //         } else if (max(node1Time[i], node2Time[i]) == len) {
        //             ans = min(ans, i);
        //         }
        //     }
        // }

        // return ans == INT_MAX ? -1 : ans;

        // 参考 https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/solutions/1710829/ji-suan-dao-mei-ge-dian-de-ju-chi-python-gr2u/
        int n = edges.size(), min_dis = n, ans = -1;
        auto calc_dis = [&](int x) -> vector<int> {
            vector<int> dis(n, n);
            for (int d = 0; x >= 0 && dis[x] == n; x = edges[x])
                dis[x] = d++;
            return dis;
        };
        auto d1 = calc_dis(node1), d2 = calc_dis(node2);
        for (int i = 0; i < n; ++i) {
            int d = max(d1[i], d2[i]);
            if (d < min_dis) {
                min_dis = d;
                ans = i;
            }
        }
        return ans;
    }
};
// @lc code=end

