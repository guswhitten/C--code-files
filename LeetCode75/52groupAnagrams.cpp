/*
Given an array of strings strs, group the anagrams together. You can 
return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a 
different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	if(strs.size() == 1) return {{strs[0]}};
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um; //map single string with a vector of strings
        for(int  i = 0; i < strs.size(); i++) {
            string str = strs[i];		//preserve original string (before sort)
            sort(strs[i].begin(), strs[i].end()); // sort string
            um[strs[i]].push_back(str);  // sorted string is key; value is vector of (original) strings
        }
        for(auto i = um.begin(); i != um.end(); i++)	//iterate thru map
		//i->first is KEY (sorted string); i->second is VALUE (array of original strings)
            ans.push_back(i -> second);  // i->second is array of anagram strings.
        return ans;
    }
};

/*
Runtime: 70 ms
Memory: 19.5 MB
*/
