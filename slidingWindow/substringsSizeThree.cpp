/*
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3) return 0;
        int ans=0;
        for (int i = 0; i < s.size()-2; i++) {
            if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
                ans++;
            }
        }
        return ans;
    }
};

/*
Runtime: 0 ms
Memory: 6.1 MB
*/
