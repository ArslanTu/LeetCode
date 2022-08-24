/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <map>
#include <stack>
#include <string>

using std::string;
using std::stack;
using std::map;

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        map<char,char> bracMap;
        bracMap['(']=')';
        bracMap['[']=']';
        bracMap['{']='}';

        stack<char> bracStack;
        for(char &prstChar:s){
            if(prstChar=='('||prstChar=='['||prstChar=='{') bracStack.push(prstChar);
            else{
                if(bracStack.empty()) return false;//出栈或访问栈顶元素前，都要检查是否栈空
                if(bracMap[bracStack.top()]==prstChar) bracStack.pop();
                else return false;
            }
        }
        return bracStack.empty()?true:false;
    }
};
// @lc code=end

