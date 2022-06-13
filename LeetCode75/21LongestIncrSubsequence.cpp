/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by 
deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (dp[dp.size()-1] < nums[i]) {    //if new value is bigger than biggest value already in subsequence
                dp.push_back(nums[i]);          //simply add it to array
            }
            else {                              //otherwise
              
              //find index of smallest # in dp[] >= nums[i]
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
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
