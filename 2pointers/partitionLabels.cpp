/*
You are given a string s. We want to partition the string into as many parts 
as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in 
order, the resultant string should be s.

Return a list of integers representing the size of these parts.
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>um;
        // filling impact of character's
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            um[ch] = i;
        }
        // making of result
        vector<int> res;
        int prev = -1;
        int maxi = 0;
        
        for(int i = 0; i < s.size(); i++){
            maxi = max(maxi, um[s[i]]);
            if(maxi == i){
                // partition time
                res.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return res;
    }
};

/*
Runtime: 11 ms
Memory:6.8 MB
*/
