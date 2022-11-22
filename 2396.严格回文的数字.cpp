/*
 * @lc app=leetcode.cn id=2396 lang=cpp
 *
 * [2396] 严格回文的数字
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
public:
    bool isStrictlyPalindromic(int n) {
        for (int i=2;i<=n-2;++i) {
            int num=n;
            string s1="";
            while(num) {
                s1+=to_string(num%i);
                num/=i;
            }
            string s2(s1.rbegin(),s1.rend());
            if (s1!=s2) return false;
        }
        return true;
    }
};
// @lc code=end

