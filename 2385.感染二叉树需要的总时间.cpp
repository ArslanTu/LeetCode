/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 *
 * [2385] 感染二叉树需要的总时间
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
public:
    int ans=0;
    int depth=-1;
    int dfs (TreeNode* root,int level,int start) {
        if (root==nullptr) return 0;
        if (root->val==start) depth=level;
        int l=dfs(root->left,level+1,start);
        bool inLeft=depth!=-1;
        int r=dfs(root->right,level+1,start);
        if (root->val==start) ans=max(ans,max(l,r));
        if (inLeft) ans=max(ans,depth-level+r);
        else ans=max(ans,depth-level+l);
        return max(l,r)+1;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,0,start);
        return ans;
    }
};
// @lc code=end

