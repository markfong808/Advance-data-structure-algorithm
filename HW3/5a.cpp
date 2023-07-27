#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // initizlize number of nodes
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for (auto &pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
            // update the indegree for new incoming edge
            indegree[pre[0]]++;
        }

        // hold course that are ready to add into the schedule
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (!indegree[i])
                q.push(i);
        }
        if (q.empty())
            return {};

        vector<int> schedule;
        while (!q.empty())
        {
            int courses = q.front();
            schedule.push_back(courses);
            q.pop();
            // iterate the adjance list of nodes
            for (int next : graph[courses])
            {
                indegree[next]--;
                if (!indegree[next])
                    q.push(next);
            }
        }
        if (schedule.size() == numCourses)
            return schedule;
        return {};
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    // initizlize number of nodes
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses);

    for (auto &pre : prerequisites)
    {
        graph[pre[1]].push_back(pre[0]);
        // update the indegree for new incoming edge
        indegree[pre[0]]++;
    }
    // Print the graph
    cout << "Graph:" << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j];
            if (j != graph[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }

    // Print the indegree
    cout << "Indegree:" << endl;
    for (int i = 0; i < indegree.size(); i++)
    {
        cout << i << ": " << indegree[i] << endl;
    }

    return 0;
}
