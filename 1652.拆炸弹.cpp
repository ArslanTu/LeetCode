/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0) for(int &e:code) e=0;
        else {
            for(int i=0;i<code.size();++i) {
                int sum=0;
                if(k>0) {
                    for(int j=0;j<k;++j) sum+=((*get(code,i+j+1))&0x0000ffff);
                    code[i]|=sum << 16;
                }else {
                    for(int j=0;j>k;--j) sum+=((*get(code,i+j-1))&0x0000ffff);
                    code[i]|=sum << 16;
                }
            }
            for(int &e:code) e=e>>16;
        }
        return code;
    }
    int* get(vector<int> v,int i) {
        if(i>=0&&i<v.size()) return &v[i];
        else if(i<0) return &v[v.size()+i];
        else return &v[i-v.size()];
    }
};
// @lc code=end

