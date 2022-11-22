/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 *
 * [2413] 最小偶倍数
 */

// @lc code=start
class Solution {
private:
    int gcd(int a,int b) {
        if (a<b) {
            a=a^b;
            b=a^b;
            a=a^b;
        }
        if (b==0) return a;
        else return gcd(b,a%b);
    }
    int lcm(int a,int b) {
        return (a*b)/gcd(a,b);
    }
public:
    int smallestEvenMultiple(int n) {
        return lcm(n,2);
    }
};
// @lc code=end

