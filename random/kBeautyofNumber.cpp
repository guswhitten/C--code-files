/*
The k-beauty of an integer num is defined as the number of substrings 
of num when it is read as a string that meet the following conditions:

It has a length of k.
It is a divisor of num.
Given integers num and k, return the k-beauty of num.

Note:

Leading zeros are allowed.
0 is not a divisor of any value.
A substring is a contiguous sequence of characters in a string.
*/

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans=0;
        for (int i = 0; i <= s.size()-k; i++) {
            string temp=s.substr(i,k);
            int temp1 = stoi(temp);
            if (temp1==0) continue;
            if (num%temp1 == 0) ans++;
        }
        return ans;
    }
};

/*
Runtime: 0 ms
Memory: 6 MB
*/
