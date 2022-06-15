/*
You are given an integer array nums. You are initially 
positioned at the array's first index, and each element in the 
array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/


//GREEDY soln.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; i++) {
            if (farthest < i) return false;
            farthest = max(i+nums[i], farthest);
        }
        return true;
    }
};

/*
Runtime: 71 ms
Memory: 48.5 MB
*/
