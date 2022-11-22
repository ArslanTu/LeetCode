/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <vector>
#include <map>
using std::map;
using std::vector;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> box;
        box[5]=0;box[10]=0;box[20]=0;
        for (int i=0;i<bills.size();++i) {
            if (bills[i]==5) ++box[5];
            else if (bills[i]==10) {
                ++box[10];
                --box[5];
                if (box[5]<0) return false;
            } else {
                ++box[20];
                if (box[10]>0&&box[5]>0) {
                    --box[10];
                    --box[5];
                } else if (box[10]<=0&&box[5]>=3) {
                    box[5]-=3;
                } else return false;
            }
        }
        return true;
    }
};
// @lc code=end

