/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
#include <vector>
#include <string>
#include <math.h>

using std::string;
using std::vector;
using std::to_string;
using std::max;
using std::pow;

//用除号和pow代替移位操作符后，程序执行效率没有明显变化

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int m = maxDepth(root); //m = height + 1
        //int n = (1 << m) - 1;
        int n = pow(2,m)-1;
        //int k = 1 << (m - 1);
        int k = pow(2,m-1);
        vector<vector<string>> res(m,vector<string>(n,""));
        int r = 0;
        //int c = n >> 1;
        int c = n/2;
        dfs(root,r,c,k,res);
        return res;
    }
    void dfs(TreeNode* root,int r,int c,int k,vector<vector<string>> &res){
        if(root==NULL) return;
        //k >>= 1;
        k/=2;
        res[r][c] = to_string(root->val);
        dfs(root->left,r+1,c-k,k,res);
        dfs(root->right,r+1,c+k,k,res);
    }
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
// @lc code=end

