/*
 * @lc app=leetcode.cn id=2381 lang=cpp
 *
 * [2381] 字母移位 II
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
    char newC(char& c,int& ops) {
        ops%=26;
        int newPos=int(c)+ops;
        if (newPos<'a') newPos+=26;
        else if (newPos>'z') newPos-=26;
        return char(newPos);
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        int m=s.size();
        vector<int> ops(m+1,0);
        for (int i=0;i<n;++i) {
            int tem=1;
            if (shifts[i][2]==0) tem=-1;
            ops[shifts[i][0]]+=tem;
            ops[shifts[i][1]+1]-=tem;
        }
        int sum=ops[0];
        for (int i=0;i<m;++i) {
            s[i]=newC(s[i],sum);
            sum+=ops[i+1];
        }

        return s;
    }
};
// @lc code=end

