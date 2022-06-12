/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each 
house, return the maximum amount of money you can rob tonight without 
alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) { 
        int n = nums.size();
      
      //declare dynamic programming array
        vector<int> dp(n);
        
      //ensure # of houses is bigger than 1
        if (n == 1) return nums[0];

      //initialize 
        dp[0]=nums[0];                  //best robber can do at the first house is rob it
        dp[1]=max(nums[0], nums[1]);    //best robber can do at 2nd house is rob the better of the 1st and 2nd houses
        
        for (int i = 2; i < n; i++) {
            dp[i]= max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

/*
Runtime: 
Memory: 
*/
