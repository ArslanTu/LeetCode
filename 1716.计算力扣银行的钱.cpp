/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        int save=0, start=0, sum=0;
        for(int i=0;i<n;++i)
        {
            if(i%7==0) save = ++start;
            else ++save;
            sum += save;
        }
        return sum;
    }
};
// @lc code=end

