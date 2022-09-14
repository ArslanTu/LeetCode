import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1619 lang=java
 *
 * [1619] 删除某些元素后的数组均值
 */

// @lc code=start
class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int low=arr[(int)(arr.length*0.05)];
        int high=arr[arr.length-(int)(arr.length*0.05)-1];
        float sum=0;
        int n=0;
        for(int num:arr) {
            if(num>=low&&num<=high) {
                ++n;
                sum+=num;
            }
        }
        return sum/n;
    }
}
// @lc code=end

