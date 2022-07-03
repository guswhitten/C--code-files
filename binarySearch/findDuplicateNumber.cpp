/*
Given an array of integers nums containing n + 1 integers where each 
integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
            if (um[nums[i]] > 1) return nums[i];
        }
        return nums[nums.size()-1];
        
    }
};

/*
Runtime: 345 ms
Memory: 83.8 MB
*/
