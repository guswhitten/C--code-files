/*
LEETCODE 75 #16

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        while (--n)
            a=(b+=a)-a;
        return b;
    }
};


/*
Runtime: 0ms
Memory:5.7 MB
*/
