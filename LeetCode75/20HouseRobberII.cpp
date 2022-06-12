/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at 
this place are arranged in a circle. That means the first house is 
the neighbor of the last one. Meanwhile, adjacent houses have a 
security system connected, and it will automatically contact the 
police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of 
each house, return the maximum amount of money you can rob tonight 
without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        
        return max(houseRobber(v1), houseRobber(v2));
    }
    int houseRobber(vector<int>& nums) {
        int n1=nums.size();
        if (n1==1) return nums[0];
        vector<int> dp(n1);
       
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for (int i = 2; i < n1; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n1-1];
    }
};

/*
Runtime: 4ms
Memory: 8 MB
*/
