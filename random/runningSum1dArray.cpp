/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return {nums[0]};
        vector<int> sum(n);
        sum[0]=nums[0];
        for (int i = 1; i < n; i++) {
            sum[i]=nums[i] + sum[i-1];
        }
        return sum;
    }
};


/*
Runtime: 4 ms
Memory: 8.4 MB
*/
