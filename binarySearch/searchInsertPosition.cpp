/*
Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the index 
where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        if (start==end) {
            return (target > nums[0] ? 1 : 0);
        }
        while (start < end) {
            int mid = (start+end)/2;
            if (target > nums[end]) return end+1;
            else if (target < nums[start]) return start;
            if (nums[mid] == target) return mid;
            else if (nums[start] == target) return start;
            else if (nums[end] == target) return end;
            else if (nums[end] > target && nums[end-1] < target) return end;
            else if (nums[mid] > target) end=mid;
            else start=mid;
        }
        return start;
    }
};


/*
Runtime: 3 ms
Memory: 9.8 MB
*/
