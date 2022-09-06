/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
#include <map>
using std::map;
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> m;
        while(head!=nullptr){
            m[head]=1;
            if(m[head->next]==1) return true;
            else head=head->next;
        }
        return false;
    }
};
// @lc code=end

