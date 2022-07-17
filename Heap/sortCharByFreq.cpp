/*
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> um;
        priority_queue<pair<int,char>> pq;
        string ans = "";
        
        //get freq of each letter in string
        for (auto c : s) {
            um[c]++;
        }
        
        //insert each pair of <freq, char> into pq
        for (auto it = um.begin(); it != um.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        
        //reprint string
        while (!pq.empty()) {
            int freq= pq.top().first;
            while (freq) {
                ans += pq.top().second;
                freq--;
            }
            pq.pop();
        }
        return ans;
        
    }
};


/*
Runtime: 16 ms
Memory: 8.5 MB
*/
