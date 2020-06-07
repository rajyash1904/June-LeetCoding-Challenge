/*

Coin Change 2

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

1. 0 <= amount <= 5000
2. 1 <= coin <= 5000
3. the number of coins is less than 500
4. the answer is guaranteed to fit into signed 32-bit integer

*/

class Solution {
public:
    int change(int val, vector<int>& c) 
    {
        int n=c.size();
        if(val==0) return 1;
        if(n==0) return 0;
       // sort(c.begin(),c.end());
        vector<vector<int>> dp(val+1,vector<int> (n,1));
        int x,y;
        for(int i=1;i<=val;i++)
        {
            for(int j=0;j<n;j++)
            {
                x=(i-c[j]>=0) ? dp[i-c[j]][j]:0;
                y=(j>=1) ? dp[i][j-1]:0;
                dp[i][j]=x+y;
            }
        }
        
        return dp[val][n-1];   
    }
};
