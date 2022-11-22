/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 *
 * [2391] 收集垃圾的最少总时间
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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // int n=garbage.size();
        // vector<map<char,int>> center(n);
        // for (int i=0;i<n;++i) {
        //     for (auto ch:garbage[i]) center[i][ch]++;
        // }
        // int timeM=0,timeP=0,timeG=0;
        // int farM=0,farP=0,farG=0;
        // for (int i=0;i<n;++i) {
        //     if (center[i]['M']!=0) {
        //         timeM+=center[i]['M'];
        //         farM=i;
        //     }
        //     if (center[i]['P']!=0) {
        //         timeP+=center[i]['P'];
        //         farP=i;
        //     }
        //     if (center[i]['G']!=0) {
        //         timeG+=center[i]['G'];
        //         farG=i;
        //     }
        // }
        // int m=travel.size();
        // vector<int> totalTime(m+1,0);
        // totalTime[1]=travel[0];
        // for (int i=2;i<=m;++i) totalTime[i]=totalTime[i-1]+travel[i-1];
        // timeM+=totalTime[farM];
        // timeP+=totalTime[farP];
        // timeG+=totalTime[farG];
        // return timeM+timeP+timeG;
        int n=garbage.size();
        int farM=0,farP=0,farG=0;
        int totalTime=0;
        for (int i=0;i<n;++i) {
            for (auto ch:garbage[i]) {
                ++totalTime;
                if (ch=='M') farM=i;
                if (ch=='P') farP=i;
                if (ch=='G') farG=i;
            }
        }
        int m=travel.size();
        vector<int> driveTime(m+1,0);
        driveTime[1]=travel[0];
        for (int i=2;i<=m;++i) driveTime[i]=driveTime[i-1]+travel[i-1];
        totalTime+=driveTime[farM]+driveTime[farP]+driveTime[farG];
        return totalTime;
    }
};
// @lc code=end

