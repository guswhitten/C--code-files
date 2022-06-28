/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int a[26] = { 0 };
        int b[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            int s1 = s[i]-'a';
            int t1 = t[i]-'a';
            a[s1]++;
            b[t1]++;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] == b[i]) continue;
            else return false;
        }
        return true;
    }
};

/*
Runtime: 
Memory: 
*/
