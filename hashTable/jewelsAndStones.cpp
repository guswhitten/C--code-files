/*
You're given strings jewels representing the types of stones that are jewels, 
and stones representing the stones you have. Each character in stones is a type 
of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> us;
        int ans = 0;
        for (int i = 0; i < jewels.size(); i++) {
            us.insert(jewels[i]);           
        }
        for (int i = 0; i < stones.size(); i++) {
            if (us.count(stones[i])) {
                ans++;
            }
        }
        return ans;
    }
};

/*
Runtime: 3 ms
Memory: 6.3 MB
*/
