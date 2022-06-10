/*
LEETCODE 75 #17
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

// Solution 1
// Brute Force / Recursion

int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(amount<0) return -1;
        int cc = -1;
        for(int i=0;i<coins.size();i++) {
            int coin = coinChange(coins,amount-coins[i]);   //use recursion to try every possibility
            if(coin>=0) {
              cc = cc < 0 ? coin : min(cc,coin);
            }
        }
        return cc <0 ? -1 : cc+1;
    }











/*
Runtime:
Memory:
*/
