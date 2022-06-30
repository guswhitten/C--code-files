/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more 
than once in a DNA molecule. You may return the answer in any order.
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 10) return {};
        unordered_map<string,int> um;
        for (int i = 0; i < s.size()-9; i++) {
            string temp = s.substr(i, 10);
            if (um[temp] == 1) {
                cout << "hi ";
                ans.push_back(temp);
            }
            um[temp]++;
            cout << i << " ";
        }
        return ans;
    }
};

/*
Runtime: 265 ms
Memory: 23.5 MB
*/
