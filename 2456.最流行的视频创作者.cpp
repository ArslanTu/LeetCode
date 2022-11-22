/*
 * @lc app=leetcode.cn id=2456 lang=cpp
 *
 * [2456] 最流行的视频创作者
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
private:
    string dir(const string& a,const string& b) {
        string c=a,d=b;
        if (a.size()>b.size()) {
            c=b;
            d=a;
        }
        for (int i=0;i<c.size();++i) {
            if (int(c[i])<int(d[i])) return c;
            else if (int(c[i])>int(d[i])) return d;
        }
        return c;
    }
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans; //答案
        map<string,long> mp1; //作者对应流行度
        map<string,int> mp2; //作者播放量最高的作品序号
        long highest=0; //最高的播放量
        int n=ids.size();
        for (int i=0;i<n;++i) {
            mp2[creators[i]]=-1;
        }

        for (int i=0;i<n;++i) {
            mp1[creators[i]]+=views[i]; //统计每个作者的流行度
            highest=mp1[creators[i]]>highest?mp1[creators[i]]:highest;
            if (mp2[creators[i]]==-1) mp2[creators[i]]=i;
            else {
                if (views[mp2[creators[i]]]<views[i]) mp2[creators[i]]=i;
                else if (views[mp2[creators[i]]]==views[i]) {
                    if (dir(ids[mp2[creators[i]]],ids[i])==ids[i]) mp2[creators[i]]=i;
                }
            }
        }

        for (auto elem:mp1) {
            if (elem.second==highest) ans.push_back(vector<string>{elem.first,ids[mp2[elem.first]]});
        }
        return ans;
    }
};
// @lc code=end

