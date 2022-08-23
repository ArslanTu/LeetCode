/*
 * @lc app=leetcode.cn id=782 lang=cpp
 *
 * [782] 变为棋盘
 */

// @lc code=start
#include <vector>
#include <math.h>

using std::abs;
using std::vector;

class Solution
{
public:
    int movesToChessboard(vector<vector<int>> &board)
    {
        int len = board.size();
        if (len <= 1) return 0;
        for(int i=0;i<len;++i){
            if(board[i]!=board[0]){
                for(int j=0;j<len;++j){
                    if(board[i][j]^board[0][j]!=1) return -1;
                }
            }
        }

        int cntR_0=0,cntR_1=0,cntC_0=0,cntC_1=0;
        for(int elem:board[0]){
            if(elem==0) ++cntR_0;
            else ++cntR_1;
        }
        for(int j=0;j<board.size();++j){
            if(board[j][0]==0) ++cntC_0;
            else ++cntC_1;
        }
        if(!(((cntR_0==cntR_1)||(abs(cntR_0-cntR_1)==1))&&((cntC_0==cntC_1)||(abs(cntC_0-cntC_1)==1)))) return -1;

        int difR = 0, difC = 0;
        for (int i = 0; i < len; ++i)
        {
            //如果首元素为0
            difR += int(board[0][i] != i % 2);
            difC += int(board[i][0] != i % 2);
        }
        //如果不同项数目为奇数，说明不是以0为首元素
        //如果矩阵阶为偶数，显然有分别以0和1为首元素的两种排列，应当选交换次数更少的那个
        if ((difR % 2 != 0) || (len % 2 == 0 && (len - difR) < difR))
            difR = len - difR; //两种排列中的不同项数加起来显然为矩阵阶数
        if ((difC % 2 != 0) || (len % 2 == 0 && (len - difC) < difC))
            difC = len - difC;
        return (difR + difC) >> 1;
    }
};
// @lc code=end
