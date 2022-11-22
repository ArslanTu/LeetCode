/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
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
    void dfs(vector<string>& paths,string path,TreeNode* root) {
        path+="->"+to_string(root->val);
        if (!root->left&&!root->right) {
            paths.push_back(path);
            return;
        }
        if (root->left) dfs(paths,path,root->left);
        if (root->right) dfs(paths,path,root->right);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root->left&&!root->right) {
            paths.push_back(to_string(root->val));
            return paths;
        }
        if (root->left) dfs(paths,to_string(root->val),root->left);
        if (root->right) dfs(paths,to_string(root->val),root->right);
        return paths;
    }
};
// @lc code=end

