/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> om;                               //using map because we don't care about order
        for (int i = 0; i < nums.size(); ++i) {
            if (om.count(target - nums[i])) {
                return {om[target - nums[i]], i};
            }
            om[nums[i]] = i;
        }
        
        return {};
    }
};

/*
Runtime 19ms
Memory 10.8MB
*/
