/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;
        }
        if(n==0) return;
        int i=m-1,j=n-1,k=m+n-1;
        while(k>=0){
            int val_1=(i<0)?nums2[j]-1:nums1[i];
            int val_2=(j<0)?nums1[i]-1:nums2[j];
            if(val_1>val_2){
                nums1[k--]=val_1;
                --i;
            }
            else{
                nums1[k--]=val_2;
                --j;
            }
        }
    }
};
// @lc code=end

