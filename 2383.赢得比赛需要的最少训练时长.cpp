/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
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
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        int totalEn=0;
        for (int elem:energy) totalEn+=elem;
        ans+=max(totalEn+1-initialEnergy,0);
        int maxGap=INT_MIN;
        int totalEx=initialExperience;
        for (int elem:experience) {
            int newGap=max(elem+1-totalEx,0);
            maxGap=max(maxGap,newGap);
            totalEx+=elem;
        }
        ans+=maxGap;
        return ans;
    }
};
// @lc code=end

