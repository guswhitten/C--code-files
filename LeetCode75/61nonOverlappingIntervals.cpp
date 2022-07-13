/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove 
to make the rest of the intervals non-overlapping.
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0, start=0, n=intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int end = 1; end < n; end++) {
            
            //non-overlapping
            if (intervals[start][1] <= intervals[end][0]) {
                start=end; 
            }
            //semi-overlapping
            else if (intervals[start][1] > intervals[end][0] && intervals[start][1] < intervals[end][1]) {
                ans++;
            }
            //overlapping "swallowed"
            else if (intervals[start][1] >= intervals[end][1]) {
                ans++;
                start=end;
            }
        }
        return ans;
    }
};

/*
Runtime: 457ms
Memory: 89.8MB
*/
