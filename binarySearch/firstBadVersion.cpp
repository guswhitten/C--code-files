/*
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality 
check. Since each version is developed based on the previous version, all the 
versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad 
one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is 
bad. Implement a function to find the first bad version. You should minimize the 
number of calls to the API.
*/

class Solution {
public:
    int firstBadVersion(long long n) {
        int start=1;
        long long end=n;
        if (n <= 2) {
            if (isBadVersion(1)) return 1;
            else return 2;
        }
        while (start<end) {
            if (isBadVersion(end) && !isBadVersion(end-1)) return end;
            long long mid = (start+end)/2;
            if (isBadVersion(mid) && !isBadVersion(mid-1)) return mid;
            
            
            //binary search
            if (!isBadVersion(mid)) start=mid;
            else end=mid;
        }
        return start;
    }
};

/*
Runtime: 0 ms
Memory: 6 MB
*/
