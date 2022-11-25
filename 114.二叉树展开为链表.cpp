/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
private:
    void trans(TreeNode* root, vector<TreeNode*>& tree) {
        if (!root) return;
        tree.push_back(root);
        trans(root->left, tree);
        trans(root->right, tree);
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> tree;
        trans(root, tree);
        for (int i = 0; i < tree.size() - 1; ++i) {
            tree[i]->left = nullptr;
            tree[i]->right = tree[i + 1];
        }
    }
};
// @lc code=end

