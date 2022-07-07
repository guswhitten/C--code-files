/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which 
has exactly n nodes of unique values from 1 to n.
*/
// Catalan Number / Binomial Coefficient approach
class Solution {
public:
        /*
        CATALAN NUMBERS (C):
        C(i) denotes # of nodes on left side of root
        C(n-i-1) denotes # of nodes on right side of root
        total # of unique BST possible for given root = C(i) * C(n-i-1)
        
        For n=3:
        C(0)*C(2) + C(1)*C(1) + C(2)*C(0)
        
        Binomial Coefficient approach:
        `C(n) = Ci(2n,n) / (n+1)`
        */
    long CalculateCoeff(int n,int k) {         //Function to calculate Ci(n.k)
        long res=1;
        if (k > n-k) k=n-k;         //Since Ci(n,k)=Ci(n,n-k)
        for (int i=0; i<k; i++) {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    int numTrees(int n) {
        /*
        write func that calculates 
        */
        return CalculateCoeff(2*n,n)/(n+1);
    }
};

// Dynamic Programming approach
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[i-j] * dp[j-1];
        
        return dp[n];
    }
}

/*
Runtime: 1 ms
Memory: 6.1 MB
*/
