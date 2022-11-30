/*
 * @lc app=leetcode.cn id=2326 lang=cpp
 *
 * [2326] 螺旋矩阵 IV
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void construct(vector<vector<int>>& ans, int m, int n, ListNode* cur, int layer) {
        for (int i = layer; i < n - layer; ++i) {
            if (cur) {
                ans[layer][i] = cur->val;
                cur = cur->next;
            }
            // else ans[layer][i] = -1;
            else return;
        }
        for (int i = layer + 1; i < m - layer; ++i) {
            if (cur) {
                ans[i][n - 1 - layer] = cur->val;
                cur = cur->next;
            }
            // else ans[i][n - 1 - layer] = -1;
            else return;
        }
        for (int i = n - 1 -layer - 1; i >= layer; --i) {
            if (cur) {
                ans[m - 1 - layer][i] = cur->val;
                cur = cur->next;
            }
            // else ans[m - 1 - layer][i] = -1;
            else return;
        }
        for (int i = m - 1 - layer -1; i > layer; --i) {
            if (cur) {
                ans[i][layer] = cur->val;
                cur = cur->next;
            }
            // else ans[i][layer] = -1;
            else return;
        }
        if (layer < (m - 1) / 2) construct(ans, m, n, cur, layer + 1);
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        construct(ans, m, n, head, 0);
        return ans;
    }
};
// @lc code=end

