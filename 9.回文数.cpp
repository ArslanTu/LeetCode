/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <stack>
#include <math.h>
#include <string>

using std::stack;
using std::pow;
using std::string;
using std::to_string;

class Solution {
public:
    bool isPalindrome(int x) {
        //数字解法2
        if(x<0) return false;
        if(x==0) return true;
        int max = 2147447412,num1=x;
        long y=0;
        for(;num1;y=y*10+num1%10,num1/=10);
        return (y>max)?false:(x==y);
        //字符串解法
        /*
        string strX = to_string(x);
        string strY;
        strY.assign(strX.rbegin(),strX.rend());
        return strX==strY;
        */

        //数字解法1
        /*
        //x为负必不是
        if(x<0) return false;
        //x为0必是
        else if(x==0) return true;
        else
        {
            //计算x的位数
            int digit_count = 1;
            long long num1 = x;
            while(num1 /= 10)
            {
                ++digit_count;
            }

            //将x由高位到低位依次入栈
            stack<int> digit_stack;
            long long num2 = x;
            int present_digit;
            for(int i=digit_count-1;i>=0;--i)
            {
                present_digit = num2/(pow(10,i));
                num2 -= present_digit*pow(10,i);
                digit_stack.push(present_digit);
            }

            //依次出栈并计算反向数y
            long long y=0;
            for(int i=digit_count-1;i>=0;--i)
            {
                present_digit = digit_stack.top();
                digit_stack.pop();
                y += present_digit*pow(10,i);
            }
            long long z = x;
            return z==y;
        }
        */

    }
};
// @lc code=end

