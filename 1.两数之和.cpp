/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::equal_range;
using std::vector;
using std::sort;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans; //作为函数的返回值

        //对nums进行排序，因为最后要返回原位置，所以另行构造
        vector<int> nums_sort(nums.begin(),nums.end());
        sort(nums_sort.begin(),nums_sort.end());

        int num1;
        int num2;
        //依次选定一个元素作为num1，则num2=target-num1
        //然后二分法查找num2是否存在
        //若存在则在原序列查找num1和num2位置并返回
        for (int i = 0; i < nums_sort.size(); ++i)
        {
            //确定num1和num2，然后删除num1
            auto iter = nums_sort.begin();
            advance(iter,i);
            num1 = *iter;
            num2 = target-num1;
            iter = nums_sort.erase(iter);
            //二分法查找，对数时间复杂度
            auto ansIter = lower_bound(nums_sort.begin(),nums_sort.end(),num2);

            //只在成功配对num1和num2的情况下进行的线性查找
            //时间复杂度n，对整体而言无影响
            if(*ansIter==num2){
                for(int j = 0;j < nums.size();++j){
                    if(nums[j]==num1) ans.insert(ans.end(),j);
                    else if (nums[j]==num2) ans.insert(ans.end(),j);
                    //两个位置都已经确定，可以直接跳出
                    if(ans.size()==2) break;
                }
                //返回值确定，跳出循环
                break;
            }
            //配对失败，把num1重新插回序列
            nums_sort.insert(iter,num1);
        }
        return ans;
    }
};
// @lc code=end
