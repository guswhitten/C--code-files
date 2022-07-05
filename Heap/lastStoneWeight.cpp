/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest 
two stones and smash them together. Suppose the heaviest two stones have weights 
x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto s : stones) {
            pq.push(s);
        }
        while (pq.size() > 1) {
            int heaviest = pq.top();
            pq.pop();
            int sHeaviest = pq.top();
            pq.pop();
            if (heaviest == sHeaviest) {
                stones.erase(find(stones.begin(), stones.end(), heaviest));
                stones.erase(find(stones.begin(), stones.end(), heaviest));
            }
            else {
                int leftover = heaviest-sHeaviest;
                stones.erase(find(stones.begin(), stones.end(), sHeaviest));
                replace(stones.begin(), stones.end(), heaviest, leftover);
                pq.push(leftover);
            }
        }        
        if (stones.size() == 1) return stones[0];
        else return 0;
    }
};

/*
Runtime: 10 ms
Memory: 7.7 MB
*/
