/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string temp1 = to_string(x);
        string temp2 = temp1;
        reverse(temp1.begin(), temp1.end());
        if (temp1 == temp2) return true;
        else return false;
    }
};


/*
Runtime: 28 ms
Memory: 5.7 MB
*/
