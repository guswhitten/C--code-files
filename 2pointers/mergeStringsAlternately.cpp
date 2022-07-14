/*
You are given two strings word1 and word2. Merge the strings by adding 
etters in alternating order, starting with word1. If a string is longer than 
the other, append the additional letters onto the end of the merged string.

Return the merged string.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged="";
        int ptr1=0, ptr2=0;
        int count=2, n;
        //n is length of shorter word
        if (word1.size() >= word2.size()) n = 2*word2.size();
        else n = 2*word1.size();
        while (n) {
            if (count%2==0) {merged+=word1[ptr1]; ptr1++;}
            else {merged+=word2[ptr2]; ptr2++;}
            count++;
            n--;
        }
        if (ptr1 < word1.size()) {
            merged+=word1.substr(ptr1,string::npos);
        }
        else if (ptr2 < word2.size()) {
            merged+=word2.substr(ptr2,string::npos);
        }
        return merged;
    }
};



/*
Runtime: 4 ms
Memory: 6.3 MB
*/
