/*
 * @lc app=leetcode.cn id=2429 lang=cpp
 *
 * [2429] 最小 XOR
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
    string convert(int x) {
        string ans="";
        while (x) {
            ans.insert(ans.begin(),x%2==0?'0':'1');
            x/=2;
        }
        return ans;
    }
public:
    int minimizeXor(int num1, int num2) {
        int cntOf1=0;
        string num1_str=convert(num1);
        string num2_str=convert(num2);
        for (int i=0;i<num2_str.size();++i) {
            if (num2_str[i]=='1') ++cntOf1;
        }
        string ans_str="";
        for (int i=0;i<num1_str.size();++i) {
            if (cntOf1==0) ans_str+='0';
            else {
                if (num1_str[i]=='1') {
                    ans_str+='1';
                    --cntOf1;
                }
                else ans_str+='0';
            }
        }
        if (cntOf1>0) {
            for (int i=ans_str.size()-1;i>=0&&cntOf1>0;--i) {
                if (ans_str[i]=='0') {
                    ans_str[i]='1';
                    --cntOf1;
                }
            }
        }
        if (cntOf1>0) {
            while (cntOf1>0)
            {
                ans_str.insert(ans_str.begin(),'1');
                --cntOf1;
            }
            
        }
        int ans=0;
        int pow=1;
        for (int i=ans_str.size()-1;i>=0;--i) {
            ans+=(int(ans_str[i])-48)*pow;
            pow*=2;
        }
        return ans;
    }
};
// @lc code=end

