/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        vector<int> res; //也可以直接把结果存在digits里，省点空间
        for(int i=digits.size()-1;carry!=0||i>=0;--i){
            int val=i<0?0:digits[i];
            res.insert(res.begin(),(val+carry)%10);
            carry = (val+carry)/10;
        }
        return res;
    }
};
// @lc code=end

