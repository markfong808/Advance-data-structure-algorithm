#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits> // For INT_MAX

using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // adj list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto x : times)
            adj[x[0]].push_back({x[1], x[2]});

        vector<int> dist(n + 1, INT_MAX); // unknown distance from source to n
        // vector<bool> visited(n+1,false);
        dist[k] = 0; // first node has 0 distance

        // Initialization for all data structures
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        minHeap.push({0, k});

        while (!minHeap.empty())
        {
            int node = minHeap.top().second;
            int distance = minHeap.top().first;
            minHeap.pop();

            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int wt = x.second;
                if (dist[adjNode] > dist[node] + wt)
                {
                    dist[adjNode] = dist[node] + wt;
                    minHeap.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxTime = -1;
        dist[0] = 0;

        for (auto x : dist)
        {
            if (x == INT_MAX)
                return -1;
            else

                maxTime = max(maxTime, x); // keep updating the maxTime
        }
        return maxTime;
    }
};

int main() { cout << "Done"; }