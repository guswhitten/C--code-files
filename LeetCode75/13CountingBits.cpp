//LEETCODE 75 #13

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i<=n; i++) {
            int sum=0;
            uint32_t m = i;
            while (m>0) {
                
                if (m & 1 > 0) {
                    sum++;
                }
                m=m>>1;
            }
            ans.push_back(sum);
        }
            
        return ans;
    }
};


/*
Runtime: 10ms
Memory: 8.6MB
*/

