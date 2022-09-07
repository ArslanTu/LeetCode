/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

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
#include <stack>
using std::stack;
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        stack<ListNode*> s;
        while(head!=nullptr){
            s.push(head);
            head=head->next;
        }
        head=s.top();
        ListNode* p=head;
        s.pop();
        while (!s.empty()){
            p->next=s.top();
            s.pop();
            p=p->next;
            p->next=nullptr; //这句必须，否则报错“释放堆后再使用”
            //https://blog.csdn.net/cncxycpp/article/details/106057900
        }
        return head;
    }
};
// @lc code=end

