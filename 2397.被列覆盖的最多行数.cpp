/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
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
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> rowNum(n);
        for (int i=0;i<n;++i) {
            int num=0;
            for (int j=0;j<m;++j) {
                num*=2;
                num+=matrix[i][j];
            }
            rowNum[i]=num;
        }

        int ans=0;
        for (int now=1;now<(1<<m);++now) {
            if ((__builtin_popcount(now))==numSelect) {
                int cnt=0;
                for (int i=0;i<n;++i) {
                    if ((now&rowNum[i])==rowNum[i]) {
                        ++cnt;
                        ans=cnt>ans?cnt:ans;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

