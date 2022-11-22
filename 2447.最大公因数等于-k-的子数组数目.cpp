/*
 * @lc app=leetcode.cn id=2447 lang=cpp
 *
 * [2447] 最大公因数等于 K 的子数组数目
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
    int gcd(int a,int b) {
        if (a<b) {
            int temp=a;
            a=b;
            b=temp;
        }
        if (b!=0) {
            return gcd(b,a%b);
        }
        else return a;
    }
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for (int i=0;i<n;++i) {
            int init=nums[i];
            for (int j=i;j<n;++j) {
                init=gcd(init,nums[j]);
                if (init%k!=0) break;
                if (init==k) ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

