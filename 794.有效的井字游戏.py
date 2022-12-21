#
# @lc app=leetcode.cn id=794 lang=python3
#
# [794] 有效的井字游戏
#

# @lc code=start
from typing import List


class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        num_O = num_X = 0
        win_O = win_X = 0
        for row in board:
            if row == "OOO": win_O += 1
            elif row == "XXX": win_X += 1
            for lattice in row:
                if lattice == "O": num_O += 1
                elif lattice == "X": num_X += 1
        if (num_X - num_O != 0) and (num_X - num_O != 1): return False
        if board[0][0] == "X" and board[1][0] == "X" and board[2][0] == "X": win_X += 1
        if board[0][1] == "X" and board[1][1] == "X" and board[2][1] == "X": win_X += 1
        if board[0][2] == "X" and board[1][2] == "X" and board[2][2] == "X": win_X += 1
        if board[0][0] == "O" and board[1][0] == "O" and board[2][0] == "O": win_O += 1
        if board[0][1] == "O" and board[1][1] == "O" and board[2][1] == "O": win_O += 1
        if board[0][2] == "O" and board[1][2] == "O" and board[2][2] == "O": win_O += 1
        if board[0][0] == "X" and board[1][1] == "X" and board[2][2] == "X": win_X += 1
        if board[0][2] == "X" and board[1][1] == "X" and board[2][0] == "X": win_X += 1
        if board[0][0] == "O" and board[1][1] == "O" and board[2][2] == "O": win_O += 1
        if board[0][2] == "O" and board[1][1] == "O" and board[2][0] == "O": win_O += 1
        if win_X > 0 and win_O > 0: return False
        if (win_X > 0 and num_X == num_O) or (win_O > 0 and num_X != num_O): return False
        return True
# @lc code=end

