/*
Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxHeap;
        for (auto n : nums) {
            maxHeap.push(n);
        }
        int first = maxHeap.top();
        maxHeap.pop();
        int second = maxHeap.top();
        return (first-1) * (second-1);
    }
};

/*
Runtime: 8 ms
Memory: 10.2 MB
*/
