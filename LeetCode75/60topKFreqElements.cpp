/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (!k) return {};
        unordered_map<int,int> um;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for (auto n : nums) {      
            um[n]++;                 //key=number; value=freq of that number
        }
        
        for (auto it=um.begin(); it != um.end(); it++) {      
            pq.push(make_pair(it->second, it->first));      //pq<freq, number>
            if (pq.size() > um.size()-k) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};

/*
Runtime: 20 ms
Memory: 13.7 MB
*/
