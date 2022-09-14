/*
 * @lc app=leetcode.cn id=374 lang=java
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low=1,high=n,gn=(low+high)>>1;
        while(guess(gn)!=0) {
            if(guess(gn)==-1) {
                high=gn-1;
                gn=(low+high)>>1;
            }else {
                low=gn+1;
                gn=(low+high)>>1;
            }
        }
        return gn;
    }
}
// @lc code=end

