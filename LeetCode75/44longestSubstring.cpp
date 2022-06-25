/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);           //vector of size 256 to account for entire ASCII table
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)         //TRUE if this character has been seen before
                //start keeps track of the index (right before the one) that begins our LOCALLY LONGEST STRING
                start = dict[s[i]];         //update start to signal a new string
            dict[s[i]] = i;                 //value at each index of dict records LAST INDEX AT WHICH the current letter was last seen
            //i - start     -->     checks the length of the current 
            maxLen = max(maxLen, i - start); 
        }
        return maxLen;
    }
};

/*
Runtime: 12 ms
Memory: 8.3 MB
*/
