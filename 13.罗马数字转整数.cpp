/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <map>
#include <stack>

using std::string;
using std::map;
using std::make_pair;

class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        map<char,int> romanMap;
        /*
        romanMap.insert(make_pair('I',1));
        romanMap.insert(make_pair('V',5));
        romanMap.insert(make_pair('X',10));
        romanMap.insert(make_pair('L',50));
        romanMap.insert(make_pair('C',100));
        romanMap.insert(make_pair('D',500));
        romanMap.insert(make_pair('M',1000));
        */
        romanMap['I']=1;
        romanMap['V']=5;
        romanMap['X']=10;
        romanMap['L']=50;
        romanMap['C']=100;
        romanMap['D']=500;
        romanMap['M']=1000;

        /*
        int temp;
        for(auto romanChar=s.begin();romanChar!=s.end();++romanChar){
            temp = romanMap[*romanChar];
            if(temp<romanMap[*(romanChar+1)]){
                sum += romanMap[*(romanChar+1)]-temp;
                ++romanChar;
            }
            else{
                sum += temp;
            }
        }
        */

        for(int i=0;i<s.length();++i){
            if(romanMap[s[i]]<romanMap[s[i+1]]){
                sum += romanMap[s[i+1]]-romanMap[s[i]];
                ++i;
            }
            else sum +=romanMap[s[i]];
        }
        return sum;
    }
};
// @lc code=end

