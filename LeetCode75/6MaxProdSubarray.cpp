/*
LEETCODE 75 #6
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Gmax=INT_MIN, Lmax=1;       
        
        //iterate forward. find max product subarray before last negative in array
        for (int i = 0; i < nums.size(); i++) {
            Gmax=max(Lmax *= nums[i], Gmax);
            if (nums[i] == 0) {Lmax = 1;}
        }
        Lmax=1;
        //iterate backwards
        for (int i = nums.size()-1; i>=0; i--) {
            Gmax=max(Lmax *= nums[i], Gmax);
            if (nums[i] == 0) {Lmax = 1;}
        }
        return Gmax;
    }
};

/*
Runtime: 24 ms
Memory Usage: 13.9 MB
*/

