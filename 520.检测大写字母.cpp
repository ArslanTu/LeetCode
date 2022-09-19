/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
#include <string>
using std::string;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if((int)word[0]>=97&&(int)word[0]<=122)
        {
            for(int i=1;i<word.size();++i)
            {
                if((int)word[i]>=65&&(int)word[i]<=90) return false;
            }
        }
        else
        {
            if((int)word[1]>=65&&(int)word[1]<=90)
            {
                for(int j=2;j<word.size();++j)
                {
                    if((int)word[j]>=97&&(int)word[j]<=122) return false;
                }
            }
            else
            {
                for(int k=2;k<word.size();++k)
                {
                    if((int)word[k]>=65&&(int)word[k]<=90) return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
