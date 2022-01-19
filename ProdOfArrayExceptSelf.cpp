/*
LEETCODE 75 #4

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.


*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(),0);
        int preProduct = 1;
        for (int i = 0; i < nums.size(); ++i) {
            answer[i] = preProduct;
            preProduct*=nums[i];
        }
        int postProduct = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            answer[i]*=postProduct;
            postProduct*=nums[i];
        }
        return answer;
    }
};

/*
Runtime: 16 ms
Memory Usage: 24 MB

*/


