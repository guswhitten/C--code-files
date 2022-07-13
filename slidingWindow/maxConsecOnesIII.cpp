/*
Given a binary array nums and an integer k, return the maximum number of 
consecutive 1's in the array if you can flip at most k 0's.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //start-> starting index of window
        //end->ending index of window
        //strategy:
        //  extend window until there are k 0's inside (our allowance)
        //  then if new index is a 0, contract starting index until you've past the first 0
        
        int start = 0, ans=0, numZeros=0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) numZeros++;             //another zero in window
            while (numZeros > k) {
                if (nums[start]==0) numZeros--;
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
