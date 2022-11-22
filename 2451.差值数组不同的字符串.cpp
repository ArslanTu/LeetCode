/*
 * @lc app=leetcode.cn id=2451 lang=cpp
 *
 * [2451] 差值数组不同的字符串
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string oddString(vector<string>& words) {
        int n=words[0].size();
        int m=n-1;
        int l=words.size();
        vector<vector<int>> difference;
        for (int i=0;i<l;++i) {
            vector<int> temp;
            for (int j=1;j<n;++j) {
                temp.push_back(int(words[i][j])-int(words[i][j-1]));
            }
            difference.push_back(temp);
        }
        int ans=-1;
        if (difference[0]!=difference[1]) {
            if (difference[0]==difference[2]) ans=1;
            else ans =0;
        }
        else {
            for (int i=1;i<l;++i) {
                if (difference[i]!=difference[0]) {
                    ans=i;
                    break;
                }
            }
        }
        return words[ans];


    }
};
// @lc code=end

