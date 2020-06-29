/*

Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png

Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1. 1 <= m, n <= 100
2. It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
      //*solution1
    
        long path=1;
        for(int i=n;i<(m+n-1);i++){
            path*=i;
            path/=(i-n+1);
        }
        return path;
        
        
        //*solution 2
     /*
        int dp[m+1][n+1];
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==1 || i==1) dp[i][j]=1;
                
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    */
    }
};