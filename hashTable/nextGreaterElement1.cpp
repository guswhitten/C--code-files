/*

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> um;
        for (int i = 0; i < nums2.size(); i++) {
            um[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++) {
            int j = um[nums1[i]];
            if (j+1 < nums2.size()) {
                for (; j < nums2.size(); j++) {
                    if (nums2[j] > nums1[i]) {ans.push_back(nums2[j]); break;}
                    else if (j==nums2.size()-1) ans.push_back(-1);
                }
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};

/*
Runtime: 18 ms
Memory: 8.9 MB
*/
