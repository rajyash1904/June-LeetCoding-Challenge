/*

Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/

class Solution {
public:
    bool isperfect(double n)
    {
        double sr=sqrt(n);
        if(sr-floor(sr)==0) return true;
        return false;
    }
    int numSquares(int n) 
    {
        vector<int> sol(n+1,INT_MAX);
        vector<int> prev;
        prev.push_back(1);
        sol[0]=0;
        sol[1]=1;
        for(int i=2;i<n+1;i++)
        {
            if(isperfect(i)) 
                {
                    sol[i]=1;
                    prev.push_back(i);
                    continue;
                }
            for(int j=prev.size()-1;j>=0;j--)
            {
                {
                    sol[i]=min(sol[prev[j]]+sol[i-prev[j]],sol[i]);
                    if(sol[i]==2) break;
                }
            }
        }
        return sol[n];
    }
};