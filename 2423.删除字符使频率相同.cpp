/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 *
 * [2423] 删除字符使频率相同
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
    bool equalFrequency(string word) {
        if (word.length()==2) return true;
        vector<int> freq(26,0);
        for (auto c:word) ++freq[c-'a'];
        int minFreq=INT_MAX;
        int maxFreq=INT_MIN;
        for (auto elem:freq) {
            if (elem!=0) {
                minFreq=min(minFreq,elem);
                maxFreq=max(maxFreq,elem);
            }
        }
        
        int maxCnt=0;
        int minCnt=0;
        for (auto elem:freq) {
            if (elem!=0) {
                if (elem==maxFreq) ++maxCnt;
                if (elem==minFreq) ++minCnt;
                if (elem!=minFreq&&elem!=maxFreq) return false;
            }
        }
        if (maxFreq==minFreq) {
            if (maxFreq==1||(maxCnt==1)) return true;
            else return false;
        }
        if (maxCnt>minCnt) {
            if (minCnt!=1) return false;
            else {
                if (minFreq!=1) return false;
            }
        } else if (maxCnt<minCnt) {
            if (maxCnt!=1) return false;
            else if (maxFreq-minFreq>1) return false;
        } else if (maxCnt!=1) return false;
        else if ((maxFreq-minFreq)>1&&minFreq>1) return false;
        return true;
    }
};
// @lc code=end

