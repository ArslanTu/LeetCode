/*
 * @lc app=leetcode.cn id=2427 lang=cpp
 *
 * [2427] 公因子的数目
 */

// @lc code=start
class Solution {
private:
    int gcd(int a,int b) {
        if (a<b) {
            int temp=a;
            a=b;
            b=temp;
        }
        if (b!=0) return gcd(b,a%b);
        else return a;
    }
public:
    int commonFactors(int a, int b) {
        int ans=2;
        int res=gcd(a,b);
        if (res==1) return 1;
        int factor=res-1;
        while (factor>1) {
            if (res%factor==0) ++ans;
            --factor;
        }
        return ans;
    }
};
// @lc code=end

