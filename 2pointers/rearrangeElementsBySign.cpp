/*
You are given a 0-indexed integer array nums of even length consisting
of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array 
follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //two queues: one positive, one negative
        //O(2n) time
        queue<int> pos;
        queue<int> neg;
        vector<int> ans(nums.size());
        int count=2;
        for (auto n:nums) {
            if (n < 0) neg.push(n);
            else if (n > 0) pos.push(n);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (count%2==0) {
                ans[i]=pos.front();
                pos.pop();
            }
            else {
                ans[i]=neg.front();
                neg.pop();
            }
            count++;
        }
        return ans;
    }
};


/*
Runtime: 506 ms
Memory: 129.8 MB
*/
