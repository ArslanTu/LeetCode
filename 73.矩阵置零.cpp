/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag_row0=false,flag_col0=false;
        for (int i=0;i<matrix.size();++i) {
            if (matrix[i][0]==0) {
                flag_col0=true; 
                break;
            }
        }
        for (int j=0;j<matrix[0].size();++j) {
            if (matrix[0][j]==0) {
                flag_row0 = true; 
                break;
            }
        }
        for (int i=1;i<matrix.size();++i) {
            for (int j=1;j<matrix[0].size();++j) {
                if (matrix[i][j]==0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i=1;i<matrix.size();++i) {
            for (int j=1;j<matrix[0].size();++j) {
                if (matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j]=0;
                }
            }
        }
        if (flag_row0) {
            for(int j=0;j<matrix[0].size();++j) matrix[0][j]=0;
        } 
        if (flag_col0) {
            for (int i =0;i<matrix.size();++i) matrix[i][0]=0;
        }
    }
};
// @lc code=end

