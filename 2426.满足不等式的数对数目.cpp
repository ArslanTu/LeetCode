/*
 * @lc app=leetcode.cn id=2426 lang=cpp
 *
 * [2426] 满足不等式的数对数目
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
class Solution {
private:
    long long ans=0;
    void mergeSort(vector<int>& nums,vector<int>& temp,int diff,int left,int right) {
        if (left>=right) return;
        int mid=left+(right-left>>1);
        mergeSort(nums,temp,diff,left,mid);
        mergeSort(nums,temp,diff,mid+1,right);

        for (int i=left,j=mid+1;j<=right;++j) {
            while (i<=mid&&nums[i]<=nums[j]+diff) ++i;
            ans+=(i-left);
        }

        for (int i=left,j=mid+1,k=left;i<=mid||j<=right;++k) {
            if (i>mid) temp[k]=nums[j++];
            else if (j>right) temp[k]=nums[i++];
            else if (nums[i]<nums[j]) temp[k]=nums[i++];
            else temp[k]=nums[j++];
        }
        for (int i=left;i<=right;++i) nums[i]=temp[i];
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ans=0;
        int n=nums1.size();
        vector<int> nums(n);
        vector<int> temp(n);
        for (int i=0;i<n;++i) nums[i]=nums1[i]-nums2[i];
        mergeSort(nums,temp,diff,0,n-1);
        return ans;
    }
};
// @lc code=end

