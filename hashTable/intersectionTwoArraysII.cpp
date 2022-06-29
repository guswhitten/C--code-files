/*
Given two integer arrays nums1 and nums2, return an array of their 
intersection. Each element in the result must appear as many times as it 
shows in both arrays and you may return the result in any order.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> ans;
        for (auto a:nums1) {
            um[a]++;
        }
        for (auto b:nums2) {
            if (um[b] > 0) {
                ans.push_back(b);
                um[b]--;
            }
        }
        return ans;
    }
};

/*
Runtime: 3 ms
Memory: 10.6 MB
*/
