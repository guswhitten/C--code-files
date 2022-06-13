/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by 
deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

//Greedy with Binary Search Soln.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (dp.back() < nums[i]) {    //if new value is bigger than biggest value already in subsequence
                dp.push_back(nums[i]);          //simply add it to array
            }
            else {                              //otherwise
              
                //find index of smallest # in dp[] >= nums[i]
                //if DNE, 
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                
                //replace 
                *it = nums[i];
            }
        }
        return dp.size();                       //return size of subsequence
    }
};

/*
Runtime: 7 ms
Memory: 10.4 MB
*/


//Dynamic Programming Soln.
class Solution { // 256 ms, faster than 42.84%
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                
                //only true when current i-th value is greater than current j-th value AND
                //current j-th value is part of a longest subsequence (represented by dp[j])  
                //that would be increased by appending nums[i] to it.
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    
                    //represent this by making dp[i] equal to the longest subsequence at 
                    //the j-th value (dp[j]) + 1
                    dp[i] = dp[j] + 1;
        
        //max_element returns an iterator pointing to index of largest value in dp[] array
        //use * to get the VALUE at that index
        return *max_element(dp.begin(), dp.end());
    }
};

/*
Runtime: 451 ms
Memory: 10.6 MB
*/

