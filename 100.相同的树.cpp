/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
#include <stack>

using std::stack;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr) return true;
        if((p==nullptr&&q!=nullptr)||(p!=nullptr&&q==nullptr)) return false;
        stack<TreeNode*> s,t;
        s.push(p);t.push(q);
        while(!s.empty()||!t.empty()){
            if((s.empty()&&!t.empty())||(!s.empty()&&t.empty())) return false;
            else{
                if((s.top()==nullptr&&t.top()!=nullptr)||(s.top()!=nullptr&&t.top()==nullptr)) return false;
                else if(s.top()==nullptr&&t.top()==nullptr){
                    s.pop();t.pop();
                }
                else{
                    if(s.top()->val!=t.top()->val) return false;
                    else{
                        TreeNode* tp=s.top(),*tq=t.top();
                        s.pop();t.pop();
                        s.push(tp->right);s.push(tp->left);
                        t.push(tq->right);t.push(tq->left);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

