/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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



#include <algorithm>

using std::swap;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 为了节约new使用的空间和时间，直接把较长的链表加到较短的链表上去
    //为此需要判断哪个长哪个短
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //首先确定两个链的长短
        int longLen=0,shortLen=0;
        //假设l1长
        ListNode* pos=l1,*longList=l1,*shortList=l2;
        while(pos!=nullptr){
            ++longLen;
            pos=pos->next;
        }
        pos=l2;
        while (pos!=nullptr)
        {
            ++shortLen;
            pos=pos->next;
        }
        //反了就交换
        if(longLen<shortLen){
            swap(longLen,shortLen);
            swap(longList,shortList);
        }
        ListNode* l3=longList;

        //开始分段处理
        int forwardNum=0; //进位
        ListNode* tail;//标出长链的尾巴
        //第一段
        //短链部分
        for(;shortList!=nullptr;shortList=shortList->next,longList=longList->next){
            longList->val += shortList->val + forwardNum;
            forwardNum=longList->val/10;
            longList->val %= 10;
            tail = longList;
        }
        //第二段
        //长链超出短链的部分
        for(;forwardNum!=0&&longList!=nullptr;longList=longList->next){
            longList->val += forwardNum;
            forwardNum = longList->val/10;
            longList->val %= 10;
            tail = longList;
        }
        //第三段
        //补上长链的尾巴
        if(forwardNum!=0){
            ListNode* temp = new ListNode;
            tail->next=temp;
            temp->val = forwardNum;
        }
        return l3;
    }
};
// @lc code=end

