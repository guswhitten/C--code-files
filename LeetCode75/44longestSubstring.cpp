/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dict[256]={0}, l=0, r=0, ans=0;
        while(r<s.length()) {   //iterate over the string till the right pointer reaches the end of the string 
            dict[s[r]]++;      //increment the count of the character present in the right pointer 
            while(dict[s[r]]>1) {   //if the occurence become more than 1 means the char is repeated 
                dict[s[l]]--;   //reduce the occurence of temp as it might be present ahead also in the string
                l++;         //contraction of the present window till the occurence of the 't' char becomes 1
            }
            ans = max(ans,r-l+1);    //As the index starts from 0 , ans will be (right pointer-left pointer + 1)
            r++;
        }
        return ans;
    }
};

/*
Runtime: 3 ms
Memory: 6.8 MB
*/
