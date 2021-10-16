class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> om;
        for (int i = 0; i < nums.size(); ++i) {
            if (om.count(target - nums[i])) {
                return {om[target - nums[i]], i};
            }
            om[nums[i]] = i;
        }
        
        return {};
    }
};
