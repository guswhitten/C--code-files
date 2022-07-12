/*
Given a binary array nums and an integer k, return the maximum number of 
consecutive 1's in the array if you can flip at most k 0's.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0, countZeros=0, ans=INT_MIN;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) countZeros++;
            while (countZeros > k) {
                if (nums[start]==0) countZeros--;
                start++;
            }
            ans=max(ans, end-start+1);
        }
        return ans;
    }
};

/*
Runtime: 82ms
Memory: 55.6 MB
*/
