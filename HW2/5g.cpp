#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int> > kClosest(vector<vector<int> > &points, int k)
    {
        priority_queue<vector<int> > maxHeap;
        vector<vector<int> > result(
            k); // initialize the vector with size k, so it can always output the
                // wanted number of closest points

        for (auto &p : points)
        {
            int x = p[0], y = p[1];
            //{distance without sqr,x coordinate , y coordinate}
            maxHeap.push({x * x + y * y, x, y});
            if (maxHeap.size() > k)
            {
                maxHeap.pop(); // pop the futher distance one
            }
        }

        for (int i = 0; i < k; i++)
        {
            // create inner vector
            vector<int> inner;
            // now the heap must have the all the cloest points after poping the
            // futherest point
            inner = maxHeap.top();
            maxHeap.pop();
            result[i] = {inner[1], inner[2]};
        }

        return result;
    }
};

int main()
{
    // vector<vector<int>> points;
    // points.push_back({3, 3});
    // points.push_back({5, -1});
    // points.push_back({-2, 4});
    // int k = 2;

    // Solution b;
    // vector<vector<int>> closestPoints = b.kClosest(points, k);

    // cout << "Closest Points: [";
    // for (int i = 0; i < closestPoints.size(); i++)
    // {
    //     cout << "[" << closestPoints[i][0] << ", " << closestPoints[i][1] << "]";
    //     if (i < closestPoints.size() - 1)
    //     {
    //         cout << ", ";
    //     }
    // }
    // cout << "]" << endl;

    // return 0;
    cout << "done " << endl;
}