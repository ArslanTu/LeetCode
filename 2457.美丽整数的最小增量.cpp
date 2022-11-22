/*
 * @lc app=leetcode.cn id=2457 lang=cpp
 *
 * [2457] 美丽整数的最小增量
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <list>
using namespace std;
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        list<int> nums;
        int sum=0;
        int len=0;
        long long ans=0;
        while (n!=0) {
            sum+=n%10;
            nums.push_back(n%10);
            n/=10;
        }
        nums.push_back(0);
        if (sum==target) return ans;

        int i=0;
        for (auto iter=nums.begin();sum>target;++iter,++i) {
            if (*iter==0) continue;
            sum-=*iter-1;
            auto iter2=iter;
			int next=1;
			++iter2;
			while (next==1) {
				++(*iter2);
				if (*iter2==10) {
					*iter2=0;
					++iter2;
                    sum-=9;
				} else next=0;
			}
            ans+=pow(10,i)*(10-*iter);
        }
        return ans;
    }
};
// @lc code=end

