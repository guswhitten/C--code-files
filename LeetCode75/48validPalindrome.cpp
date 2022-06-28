/*
A phrase is a palindrome if, after converting all uppercase letters 
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                if (isupper(s[i])) {
                    temp.push_back(s[i]+32);        //convert to lowercase
                }
                else {
                    temp.push_back(s[i]);
                }
            }
        }
        string ans=temp;
        reverse(temp.begin(), temp.end());
        if (ans == temp) return true;
        else return false;
    }
};

/*
Runtime: 17 ms
Memory: 7.9 MB
*/
