/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the 
same character, but a character may map to itself.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> um1;       //key=s[i], value=t[i]
        unordered_map<char, char> um2;       //key=t[i], value=s[i]
        for (int i = 0; i < s.size(); i++) {
            if (um1.find(s[i]) != um1.end()) {        //searches map to see if this char from string s has been input already
                if (um1[s[i]] != t[i]) return false;
            }
            else if (um2.find(t[i]) != um2.end()) {
                if (um2[t[i]] != s[i]) return false;
            }
            else {
                um1[s[i]] = t[i];
                um2[t[i]] = s[i];
            }
        }
        return true;
    }
};

/*
Runtime: 14ms
Memory: 7 MB
*/
