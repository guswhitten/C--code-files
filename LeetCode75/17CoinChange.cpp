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
Runtime: Time Limit Exceeded
Memory:
*/

// Solution 2
// Memoization, Depth First Search

class Solution {
public:
      int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> mem;
        return coinChange(amount,mem,coins);    
    }
    int coinChange(int amount, unordered_map<int,int>& mem, vector<int>& coins) {
        if(amount==0) return 0;
        if(amount<0) return -1;
        auto it = mem.find(amount);
        if(it != mem.end()) return it->second;
        int cc = amount+1;
        for(int i=0;i<coins.size();i++) {
            int coin = coinChange(amount-coins[i],mem,coins);
            if(coin>=0) cc = min(cc,coin);
        }
        return mem[amount] = cc > amount ? -1 : cc+1;
    }
};

/*
Runtime: 483 ms
Memory: 65.1 MB
*/

// Solution 3

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            
    //create vector need w/ size (amount+1) all w/ values (amount+1)
    vector<int> need(amount+1, amount+1); 
            
    //first value of need is 0
    need[0] = 0;
    sort(coins.begin(), coins.end());    
    //iterate thru coins vector
    for (int c : coins)
        //then iterate thru every 
        for (int a=c; a<=amount; a++)
            //
            need[a] = min(need[a], need[a-c] + 1);
    return need.back() > amount ? -1 : need.back();
    }
};

/*
Runtime: 69 ms
Memory: 14.5 MB
*/




