/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

/*
作者：南星
链接：https://leetcode.cn/u/nan-xing-3/
*/

#include <string>
#include <math.h>

using std::max;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128];
        for(int i=0;i<128;++i){
            last[i]=-1;
        }
        int n =s.size();
        int res=0;
        int start=0;
        for(int i=0;i<n;++i){
            int index=int(s[i]);
            start=max(start,last[index]+1);
            res=max(res,i-start+1);
            last[index]=i;
        }
        return res;
    }
};

/*
#include <string>
#include <map>

using std::map;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int totalLen=s.size();
        if(totalLen<=1) return totalLen;

        map<char,int> apNum,tempMap;
        for(int m=0;m<totalLen;++m){
            apNum[s[m]]=0;
        }
        int noDupLen=1,j=0;
        for(int i=0;i<totalLen;++i){
            tempMap=apNum;
            tempMap[s[i]]=1;
            for(j=i+1;j<totalLen;++j){
                if(tempMap[s[j]]==0) tempMap[s[j]]=1;
                else break;
            }
            noDupLen=((noDupLen>(j-i))?noDupLen:(j-i));
            if(noDupLen>=totalLen-i || noDupLen>=apNum.size()) break;
        }
        return noDupLen;
    }
};
*/
// @lc code=end