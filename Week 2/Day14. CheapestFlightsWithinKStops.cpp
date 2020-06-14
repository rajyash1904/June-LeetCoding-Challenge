/*

Cheapest Flights Within K Stops

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph looks like this: https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png

The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.


Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this: https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png

The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

1. The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
2. The size of flights will be in range [0, n * (n - 1) / 2].
3. The format of each flight will be (src, dst, price).
4. The price of each flight will be in the range [1, 10000].
5. k is in the range of [0, n - 1].
6. There will not be any duplicated flights or self cycles.

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(vector<int> & f : flights )
        {
            adj[f[0]].push_back({ f[1], f[2] });
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > mp;
        mp.push({0,src,K+1});
        
        while(!mp.empty())
        {
            auto m =mp.top();
            mp.pop();
            int cost =m[0];
            int p1 = m[1];
            int p2 = m[2];
            
            if(p1==dst) return cost;
            
            if(p2>0)
            {
                for(auto n : adj[p1])
                    mp.push({cost+n.second,n.first,p2-1});
            }
        }
        return -1;
        
    }
};
