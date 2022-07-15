/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums 
such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and 
pj is the new position of the jth element. For elements less than pivot, if i < j and 
nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than 
pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
Return nums after the rearrangement.
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int numPivots=0, ptr1=0;
        queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {                
                nums[ptr1]=nums[i];
                ptr1++;
            }
            else if (nums[i] > pivot) {
                q.push(nums[i]);
            }
            else {
                numPivots++;
            }
        }
        //construct rest:
        while (numPivots>0 || !q.empty()) {
            if (numPivots >0) {
                nums[ptr1]=pivot;
                numPivots--;
                ptr1++;
            }
            else {
                nums[ptr1]=q.front();
                ptr1++;
                q.pop();
            }
        }
        return nums;
    }
};

/*
Runtime: 319 ms
Memory: 125.3 MB
*/
