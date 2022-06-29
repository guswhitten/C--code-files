/*
You are given a string s and an integer k. You can choose any character 
of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter 
you can get after performing the above operations.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        //use sliding window approach
        unordered_map<char, int> um;        //stores frequency of letter
        int windowStart=0;                  //keeps track of window's starting index
        int windowEnd=0;                    //keeps track of window's ending index
        int maxi=0;                         //keeps track of most frequent letter in string
        int n=s.size();
        int ans=-1;                         //return -1 if string is empty
        while (windowEnd < n) {             //iterate thru string
            um[s[windowEnd]]++;             //map freq of each letter
            maxi=max(maxi, um[s[windowEnd]]);       
            if ((windowEnd-windowStart+1) - maxi > k) {       //CURRENT WINDOW
                um[s[windowStart]]--;                 //remove first letter from map
                windowStart++;                        //
            }
            ans=max(ans, (windowEnd-windowStart+1));
            windowEnd++;
        }
        return ans;
    }
};

/*
Runtime: 10 ms
Memory: 7 MB
*/
