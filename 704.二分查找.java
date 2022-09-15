/*
 * @lc app=leetcode.cn id=704 lang=java
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int low=0,high=nums.length-1,mid=(low+high)>>1;
        while(low<=high) {
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
            mid=(low+high)>>1;
        }
        return -1;
    }
}
// @lc code=end

