/*
 * @lc app=leetcode.cn id=1979 lang=cpp
 *
 * [1979] 找出数组的最大公约数
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int low = nums[0], high = nums[0];
        for (int e : nums)
        {
            low = e < low ? e : low;
            high = e > high ? e : high;
        }
        int surplus;
        do
        {
            surplus=high%low;
            high=low;
            low=surplus;
        }while (surplus != 0 && surplus!=1);
        return surplus==1?1:high;
    }
};
// @lc code=end
