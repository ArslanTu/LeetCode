/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
class Solution {
private:
    const long MOD=1e9 + 7;
    int gcd(int a,int b) {
        if (a<b) {
            a^=b;
            b^=a;
            a^=b;
        }
        if (b==0) return a;
        else return gcd(b,a%b);
    }
    int lcm(int a,int b) {
        return (a*b)/gcd(a,b);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        long lcmNum=lcm(a,b);
        long left=0,right=(long)min(a,b)*n;
        while (left+1<right) {
            long mid=left+(right-left)/2;
            if (mid/a+mid/b-mid/lcmNum>=n) {
                right =mid;
            } else left=mid;
        }
        return right%MOD;
    }
};
// @lc code=end

