/*
 * @lc app=leetcode.cn id=2384 lang=cpp
 *
 * [2384] 最大回文数字
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
    string largestPalindromic(string num) {
        sort(num.begin(),num.end());
        string mid="";
        string preHalf="";
        int n=num.size();
        if (n==1) return num;
        bool flag=false;
        for (int i=n-2;i>=0;--i) {
            if (num[i]!=num[i+1]) {
                if (mid=="") mid=num[i+1];
            }
            else {
                if (num[i]=='0') {
                    if (flag) preHalf+=num[i];
                } else {
                    flag=true;
                    preHalf+=num[i];
                }
                --i;
                if (i==0&&mid=="") mid=num[0];
            }
        }
        string backHalf(preHalf.rbegin(),preHalf.rend());
        if (preHalf==""&&mid=="") mid="0";
        preHalf+=mid+backHalf;
        return preHalf;
    }
};
// @lc code=end

