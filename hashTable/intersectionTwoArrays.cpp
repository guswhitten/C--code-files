/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us(nums1.begin(),nums1.end());
        vector<int> ans;
        for (auto n:nums2) {
            if (us.count(n)) {
                ans.push_back(n);
                us.erase(n);
            }
        }
        return ans;
    }
};

/*
Runtime: 8 ms
Memory: 10.3 MB
*/
