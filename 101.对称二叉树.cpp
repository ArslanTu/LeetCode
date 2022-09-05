/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <stack>
using std::stack;
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if((root->left==nullptr&&root->right==nullptr)||root==nullptr) return true;
        if((root->left==nullptr&&root->right!=nullptr)||(root->left!=nullptr&&root->right==nullptr)) return false;
        stack<TreeNode*> s,t;
        s.push(root->left);t.push(root->right);
        while(!s.empty()||!t.empty()){
            if((s.empty()&&!t.empty())||(!s.empty()&&t.empty())) return false;
            TreeNode* p=s.top(),*q=t.top();
            s.pop();t.pop();
            if(p->val!=q->val) return false;
            if((p->right==nullptr&&q->left!=nullptr)||(p->right!=nullptr&&q->left==nullptr)) return false;
            else if(p->right!=nullptr&&q->left!=nullptr){
                s.push(p->right);
                t.push(q->left);
            }
            if((p->left==nullptr&&q->right!=nullptr)||(p->left!=nullptr&&q->right==nullptr)) return false;
            else if(p->left!=nullptr&&q->right!=nullptr){
                s.push(p->left);
                t.push(q->right);
            }
        }
        return true;
    }
};
// @lc code=end

