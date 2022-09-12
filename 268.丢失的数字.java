/*
 * @lc app=leetcode.cn id=268 lang=java
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
    public int missingNumber(int[] nums) {
        for(int i=0;i<nums.length;++i) {
            //0存在，给首位元素高16位赋全1
            if((nums[i]&0x0000ffff)==0) nums[0] |= 0xffff0000;
            //如果当前数字不是0或n，则将其存储在对应位置的高16位
            if((nums[i]&0x0000ffff)!=nums.length) {
                nums[nums[i]&0x0000ffff]|=(nums[i]&0x0000ffff)<<16;
            }
        }
        int j=0;
        //先判断首位元素高16位是否全1，不是的话说明缺0
        if((nums[0]&0xffff0000)!=0xffff0000) return 0;
        //不缺0，从第二个元素开始遍历即可
        else ++j;
        for(;j<nums.length;++j) {
            //高16位数字与下标不符，说明缺少下标数字
            if(nums[j]>>16!=j) return j;
        }
        //正常完成遍历退出，说明缺了n
        return nums.length;
    }
}
// @lc code=end

