/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
//考察二分法
#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid=(low+high)>>1;
        for(;low<high;mid=(low+high)>>1){
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) low=mid+1;
            if(nums[mid]>target) high=mid-1;
        }
        return nums[low]<target?low+1:low;
    }
};
/*
不会发生low=mid+1后low>high
只有high=mid-1后low>high
此时high位元素小于目标，low位元素大于目标，返回low
而如果low==high，也是判断low位
如果low位小于目标，返回low+1
如果low位大于目标，返回low
*/
// @lc code=end

