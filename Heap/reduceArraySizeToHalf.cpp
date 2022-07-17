/*
You are given an integer array arr. You can choose a set of integers and 
remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> um;          //<value,freq>
        priority_queue<int> pq;
        
        int target = arr.size()/2, count=0, sum=arr.size();
        
        for (auto i:arr) {          //get freq of each num in arr
            um[i]++;
        }
        auto it2 = um.end();
        for (auto it = um.begin(); it != it2; it++) {  //iterate thru map
            pq.push(it->second);
        }
        while (sum > target) {
            sum -= pq.top();
            count++;
            pq.pop();
        }
        return count;
    }
};



/*
Runtime: 261 ms
Memory: 78.3 MB
*/
