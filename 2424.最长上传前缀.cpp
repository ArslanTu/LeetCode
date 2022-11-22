/*
 * @lc app=leetcode.cn id=2424 lang=cpp
 *
 * [2424] 最长上传前缀
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
class LUPrefix {
private:
    vector<int> stream;
    int front;
public:
    LUPrefix(int n) {
        vector<int> vec(n+2,0);
        stream=vec;
        front=0;
    }
    
    void upload(int video) {
        ++stream[video];
        for (int i=front+1;front<stream.size();++i) {
            if (stream[i]==1) ++front;
            else break;
        }
    }
    
    int longest() {
        return front;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
// @lc code=end

