/*
Given an array of distinct integers nums and a target integer 
target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.
*/

class Solution {
public:

    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i)
    {
        if(target == 0) { // if we get exact answer
            res.push_back(r);
            return;
        }
        
        while(i <  candidates.size() && target - candidates[i] >= 0) { // Till every element in the array starting from i is checked
            r.push_back(candidates[i]); // add them to vector
            Sum(candidates,target - candidates[i],res,r,i); // recur for next numbers
            ++i;
            r.pop_back(); // Remove number from vector (backtracking)
        }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());                                          // sort
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());     // removes CONSECUTIVE duplicates
        
        vector<int> r;
        vector<vector<int> > res;
        
        Sum(candidates,target,res,r,0);
        
        return res;
    }
};



/*
Runtime: 13 ms
Memory: 11 MB
*/
