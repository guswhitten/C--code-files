/*
LEETCODE 75: #1

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;                               //using map because we don't care about order
        for (int i = 0; i < nums.size(); ++i) {                   
            if (um.count(target - nums[i])) {                     //executes if diff. btwn target and current array value is a key already in the map
                return {um[target - nums[i]], i};                 //since only 1 soln, return ith array index of 1st number in pair, followed by second index
            }
            um[nums[i]] = i;                                      //key= ith value in array nums; value= ith position
        }
        
        return {};
    }
};

/*
Runtime 19ms
Memory 10.8MB
*/
