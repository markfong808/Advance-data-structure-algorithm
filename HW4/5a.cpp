#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                // two points cannot be equal
                if (i != j)
                {
                    int cost = abs(points[i][0] - points[j][0]) +
                               abs(points[i][1] - points[j][1]);
                    // add the vecotor associated with the node 'i'
                    // create edge from node i to node j
                    adj[i].push_back({j, cost});
                }
            }
        }
        // store the shortesr distance from source node
        vector<int> dist(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        // dist[0] = 0

        int result = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if (dist[node] != -1)
                continue;

            dist[node] = 0;
            result += cost;

            for (auto it : adj[node])
            {
                int newNode = it.first;
                int newCost = it.second;

                if (dist[newNode] == -1)
                {
                    pq.push({newCost, newNode});
                }
            }
        }
        return result;
    }
};
int main() { cout << "Done\n"; }