/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.

Return the indices of the two numbers, index1 and index2, as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0, last = numbers.size()-1;                 // numbers.size() is total number of indices in the given integer array
        while(first < last){                                    // -1 to get the last index 
            if((numbers[first]+numbers[last]) > target){        // since numbers are in increasing order, the latter index causes sum to be greater than target
                last--;                                         // so decrement from last index 
            }
            else if((numbers[first]+numbers[last]) < target){   // if sum of largest and smallest values is less than target, lower index must be incremented
                first++;
            }
            else{                                               // if numbers[first] + numbers[last] == target, end loop we found our two indices
                break;
            }
        }
        return {first+1, last+1};                               // since the 1st index of array is 0, both indices must be incremented
    }
};

/*
Runtime 4ms
Memory 9.7MB
*/
