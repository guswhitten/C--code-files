/*
LEETCODE 75 #11

Given two integers a and b, return the sum of the two integers without using the operators + and -.
*/

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int sum=a&b;
            a = a^b;
            b = (unsigned)sum << 1;
        }
        return a;
    }
};

/*
Runtime: 0ms
Memory: 5.9MB
*/
