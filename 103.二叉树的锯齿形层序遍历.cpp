/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> dq;
        vector<vector<int>> ans;
        dq.push_back(root);
        int seq = 0;
        while (!dq.empty()) {
            int size = dq.size();
            ans.push_back({});
            for (int i = 0; i < size; ++i) {
                if (seq % 2 == 0) {
                    TreeNode* cur = dq.front();
                    dq.pop_front();
                    ans[ans.size()-1].push_back(cur->val);
                    if (cur->left) dq.push_back(cur->left);
                    if (cur->right) dq.push_back(cur->right);
                } else {
                    TreeNode* cur = dq.back();
                    dq.pop_back();
                    ans[ans.size()-1].push_back(cur->val);
                    if (cur->right) dq.push_front(cur->right);
                    if (cur->left) dq.push_front(cur->left);
                }
            }
            seq++;
        }
        return ans;
    }
};
// @lc code=end

