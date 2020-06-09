/*

Is Subsequence

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

1. 0 <= s.length <= 100
2. 0 <= t.length <= 10^4
3. Both strings consists only of lowercase characters.

*/

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        if(n>m) return false;
        if(n==m && s==t) return true;
        int j=0;
        for(int i=0;i<m && j<n;i++)
        {
            if(s[j]==t[i]) j++;
        }
        return (j==n);
    }
};
