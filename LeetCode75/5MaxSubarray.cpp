/*
LEETCODE 75 #5

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localMax=nums[0], globalMax=nums[0];
        for (int i = 1; i<nums.size(); ++i) {
            localMax=max(localMax + nums[i], nums[i]);
            globalMax=max(globalMax, localMax);            
        }
        
        return globalMax;
    }
};


/*
Runtime: 139 ms
Memory Usage: 67.8 MB
*/
