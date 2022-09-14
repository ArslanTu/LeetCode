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
        int low=(int)(arr.length*0.05);
        int high=(int)(arr.length*0.95);
        double sum=0;
        int n=0;
        for(int i=low;i<high;++i) {
            ++n;
            sum+=arr[i];
        }
        return sum/n;
    }
}
// @lc code=end

