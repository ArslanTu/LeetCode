/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //时间O(n)，空间O(1)，利用空闲位做标记
        for(int i = 0; i < 2 * n; i ++){
            int j = i < n ? 2 * i : 2 * (i - n) + 1;
            nums[j] |= (nums[i] & 1023) << 10;
        }
        for(int& e: nums) e >>= 10;
        return nums;

        //时间O(n)，空间O(1)，以符号做标记
        // if(n==1) return nums;
        // nums[0] *= -1;
        // nums[2*n-1] *= -1;
        // int i=1;
        // int p=i;
        // while(i<2*n-1){
        //     if(nums[i]<0) p=++i;
        //     else{
        //         p=(p<n)?(2*p):((p-n)*2+1);
        //         int temp=nums[p];
        //         nums[p]=-nums[i];
        //         if(p!=i) nums[i]=temp;
        //     }
        // }
        // for(int &num:nums) num *= -1;
        // return nums;

        //时间O(n)，空间O(n)
        // vector<int> res(2*n);
        // int i=0,j=n;
        // for(int k=0;k<2*n;++k) res[k]=(k%2==0)?(nums[i++]):(nums[j++]);
        // return res;

        //时间O(n^2)，空间O(1)
        // for(int i=1;i<n;++i){//i标志起始值
        //     int j=i;
        //     int k=n;
        //     for(;j<n;++j,++k){
        //         int temp=nums[j];
        //         nums[j]=nums[k];
        //         nums[k]=temp;
        //     }
        // }
        // return nums;
    }
};
// @lc code=end

