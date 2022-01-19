/*
LEETCODE 75 #3

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for (auto num : nums) {
            umap[num]++;
            if (umap[num] > 1) {
                return true;
            }
        }
        return false;
    }
};


/*
Runtime: 146 ms
Memory Usage: 51.5 MB

*/
