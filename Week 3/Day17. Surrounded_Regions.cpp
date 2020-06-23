/*

Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

class Solution {
public:
    void floodFillUtil(vector<vector<char>> &A, int x, int y, char prevV, char newV) 
{ 
    // Base cases
    int M=A.size();
    int N=A[0].size();
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (A[x][y] != prevV) 
        return; 
  
    // Replace the color at (x, y) 
    A[x][y] = newV; 
  
    // Recur for north, east, south and west 
    floodFillUtil(A, x+1, y, prevV, newV); 
    floodFillUtil(A, x-1, y, prevV, newV); 
    floodFillUtil(A, x, y+1, prevV, newV); 
    floodFillUtil(A, x, y-1, prevV, newV); 
} 
    
    void solve(vector<vector<char>>& A) {
        
        int M=A.size();
        if(M==0) return;
   int N=A[0].size();
   for (int i=0; i<M; i++) 
      for (int j=0; j<N; j++) 
          if (A[i][j] == 'O') 
             A[i][j] = '-'; 
  
   // Call floodFill for all '-' lying on edges 
   for (int i=0; i<M; i++)   // Left side 
      if (A[i][0] == '-') 
        floodFillUtil(A, i, 0, '-', 'O'); 
   for (int i=0; i<M; i++)  //  Right side 
      if (A[i][N-1] == '-') 
        floodFillUtil(A, i, N-1, '-', 'O'); 
   for (int i=0; i<N; i++)   // Top side 
      if (A[0][i] == '-') 
        floodFillUtil(A, 0, i, '-', 'O'); 
   for (int i=0; i<N; i++)  // Bottom side 
      if (A[M-1][i] == '-') 
        floodFillUtil(A, M-1, i, '-', 'O'); 
  
   // Step 3: Replace all '-' with 'X' 
   for (int i=0; i<M; i++) 
      for (int j=0; j<N; j++) 
         if (A[i][j] == '-') 
             A[i][j] = 'X';
    }
};
