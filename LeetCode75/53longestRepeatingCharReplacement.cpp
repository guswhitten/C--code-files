/*
You are given a string s and an integer k. You can choose any character 
of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter 
you can get after performing the above operations.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        //use sliding window approach
        unordered_map<char, int> um;
        int i=0, j=0, maxi=0, n=s.size();
        int ans=-1;
        while (j < n) {
            um[s[j]]++;
            maxi=max(maxi, um[s[j]]);
            if ((j-i+1) - maxi > k) {
                um[s[i]]--;
                i++;
            }
            ans=max(ans, (j-i+1));
            j++;
        }
        return ans;
    }
};

/*
Runtime: 10 ms
Memory: 7 MB
*/
