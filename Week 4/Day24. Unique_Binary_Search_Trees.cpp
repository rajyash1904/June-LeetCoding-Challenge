/*

Unique Binary Search Trees


Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

class Solution {
public:
    long binomialcoff(int n,int k)
    {
        long res=1;
        if(k> n-k)  k=n-k;
        
        for (int i = 0; i < k; ++i) 
        { 
            res *= (n - i); 
            res /= (i + 1); 
        } 
        return res; 
    }
    
    int catalan(int n)
    {
        long k=binomialcoff(2*n,n);
        k=k/(n+1);
        return k;
    }
    
    int numTrees(int n) 
    {
        return catalan(n);
    }
};

/*
Solution Approach:
	Total number of possible Binary Search Trees with n different keys 	(countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!)
*/