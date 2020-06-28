/*

Reconstruct Itinerary


Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

*/

class Solution {
public:
    using Tickets = unordered_map<string, vector<pair<string, bool>>>;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        count = tickets.size() + 1;
        stops.resize(count);
        
        for (auto t: tickets) {
            all[t[0]].push_back({t[1], false});
        }
        for (auto &t: all) {
            auto &to = t.second;
            sort(to.begin(), to.end(), 
                [](auto &t1, auto &t2) { return t1.first < t2.first; } );
        }
        go("JFK");
        
        return stops;
    }
    
    void go(const string &from) {
        auto &to = all[from];
        for (auto &stop: to) {
            if (stop.second) { continue; }
            stop.second = true;
            go(stop.first);
        }
        stops[--count] = from;
    }
    
    
private:
    Tickets all;
    vector<string> stops;
    int count;
};