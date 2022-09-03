/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>

using std::vector;
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> a,b;
        ListNode* pa=headA,*pb=headB;
        while(pa!=nullptr){
            a.insert(a.end(),pa);
            pa=pa->next;
        }
        while(pb!=nullptr){
            b.insert(b.end(),pb);
            pb=pb->next;
        }
        auto ritera=a.rbegin();
        auto riterb=b.rbegin();
        ListNode* temp=nullptr;
        for(;ritera!=a.rend()&&riterb!=b.rend()&&*ritera==*riterb;++ritera,++riterb) temp=*ritera;
        return temp;
    }
};
// @lc code=end

