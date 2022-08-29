/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
/*
使用牛顿迭代法
*/

#include <math.h>

using std::abs;

class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        double root=x/2;
        while(abs(root*root - x)>=1) root=(root+x/root)/2;
        return int(root);
    }
};
// @lc code=end

