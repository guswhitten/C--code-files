/*
LEETCODE 75 #3

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        //create map where 
        //key={number in array 'nums'}
        //value={frequency of that number}
        unordered_map<int,int> umap;
        
        //iterate thru array
        for (auto num : nums) {
            
            //increase frequency of current number by one
            umap[num]++;
            
            //if frequency ever exceeds 1 for any number, end program
            if (umap[num] > 1) {
                return true;
            }
        }
        
        //no frequency ever exceeds 1 for any number. Unique array
        return false;
    }
};


/*
Runtime: 146 ms
Memory Usage: 51.5 MB

*/
