/*
You have k lists of sorted integers in non-decreasing order. 
Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or
a < c if b - a == d - c.
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered;                     // (value, k-th list)
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());               //every value in nums matrix sorted in ascending

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> um;                         //key=kth list; value=freq
        
        for (size_t j = 0; j < ordered.size(); ++j) {
            if (um[ordered[j].second]++ == 0) ++k;          //first time each list is seen
            if (k == nums.size()) {                         //once each list is seen at least once
                while (um[ordered[i].second] > 1) {         //
                    --um[ordered[i++].second];              // minialize range
                }
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }
        return ans;
    }
};


/*
Runtime: 125 ms
Memory: 17.2 MB
*/
