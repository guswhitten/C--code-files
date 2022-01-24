/*
LEETCODE 75 #6
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0], l = 1, r = 1,n=nums.size();
        for (int i = 0; i < n; ++i) {
            l=l*nums[i];
            r=r*nums[n-1-i];
            res=max(res,max(l,r));
            if(l==0) l=1;
            if(r==0) r=1;
        }
        return res;
    }
};

/*
Runtime: 18 ms
Memory Usage: 13.8 MB
*/

