/*
LEETCODE 75 #6
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=nums[0], max=nums[0];
        for (int i = 0; i < nums.size(); i++) {
            product=nums[i];
            if (product > max) {
                max=product;
            }
            if (nums[i]==1) {continue;}
            for (int j = i+1; j < nums.size(); j++) {
                product*=nums[j];
                if (product > max) {
                    max = product;
                }
                
                if ((product==0) && (nums[j]>max)) {
                    max=nums[j];
                }
                
                
            }
            
        }
        return max;
    }
};

/*
Runtime: 325 ms
Memory Usage: 13.8 MB
*/

