/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //原数组长度oriLen
        int oriLen = nums.size();
        //如oriLen为0或1，直接返回
        if(oriLen==0) return 0;
        if(oriLen==1) return 1;
        
        //返回的长度aftLen，初值1
        int aftLen=1;
        //首个可插入位firstBlankPos，初值-1，表示无
        int firstBlankPos=-1;
        //当前重复对比元素dupElem，初值nums[0]
        int dupElem=nums[0];
        
        //第一个for，找第一个重复元素
        //找到后将首可插入位置为该位
        //记录位置
        for(int i=1;i<oriLen;++i){
            if(nums[i]==dupElem){
                firstBlankPos=i;
                break;
            }
            else{
                dupElem=nums[i];
                ++aftLen;
            }
        }
        //找不到，说明无重复
        if(firstBlankPos==-1) return oriLen;

        //找到了，继续
        for(int j=firstBlankPos+1;j<oriLen;++j){
            if(nums[j]==dupElem){}
            else{
                nums[firstBlankPos]=nums[j];
                dupElem=nums[j];
                ++firstBlankPos;
                ++aftLen;
            }
        }
        return aftLen;
    }
};
// @lc code=end

