/*
You are given an integer array score of size n, where score[i] is the score of the 
ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the 
highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement 
of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., 
the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size(), "");
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }
        int count = 1;
        while (!pq.empty()) {
            if (count == 1) {
                ans[pq.top().second] = "Gold Medal";
            }
            else if (count == 2) {
                ans[pq.top().second] = "Silver Medal";
            }
            else if (count == 3) {
                ans[pq.top().second] = "Bronze Medal";
            }
            else {
                ans[pq.top().second] = to_string(count);
            }
            count++;
            pq.pop();
            
        }
        return ans;
    }
};


/*
Runtime: 24 ms
Memory: 10.3 MB
*/
