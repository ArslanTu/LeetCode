/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ans;
    void backtracking(TreeNode* root, int target, vector<int> path, int sum) {
        path.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == target) ans.push_back(path);
            return;
        }
        // if (sum >= target) return;

        if (root->left) backtracking(root->left, target, path, sum);
        if (root->right) backtracking(root->right, target, path, sum);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        if (!root) return ans;
        backtracking(root, targetSum, vector<int>(), 0);
        return ans;
    }
};
// @lc code=end

