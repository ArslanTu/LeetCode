/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
 */

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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

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
private:
    vector<vector<TreeNode*>> tree;
    void dfs(TreeNode* root, int depth) {
        if (root==nullptr) return;
        if (tree.size()<depth+1) tree.push_back(vector<TreeNode*>());
        tree[depth].push_back(root);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        tree.clear();
        dfs(root,0);
        int n=tree.size();
        for (int i=0;i<n;++i) {
            if (i&1==1) {
                int m=tree[i].size();
                int k=m>>1;
                for (int j=0;j<k;++j) {
                    tree[i][j]->val=tree[i][j]->val^tree[i][m-1-j]->val;
                    tree[i][m-1-j]->val=tree[i][j]->val^tree[i][m-1-j]->val;
                    tree[i][j]->val=tree[i][j]->val^tree[i][m-1-j]->val;
                }
            }
        }
        return tree[0][0];
    }
};
// @lc code=end

