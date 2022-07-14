/*
Given a string s, reverse the order of characters in each word within a sentence 
while still preserving whitespace and initial word order.
*/

class Solution {
public:
    string reverseWords(string s) {
        string str;
        int start=0;
        for (int end = 0; end < s.size(); end++) {
            string temp = "";
            while (s[end] != ' ' && end < s.size()) {
                temp+=s[end];
                end++;
            }
            reverse(temp.begin(), temp.end());
            str+=temp;
            if (end < s.size()) str+= ' ';
            start=end;
        }
        return str;
    }
};


/*
Runtime: 20 ms
Memory: 13.2 MB
*/
