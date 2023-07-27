#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  // global data structure
  queue<pair<int, int>> q;

  // dfs to find a island
  void dfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int x, int y)
  {
    // out of bound
    // current cell is not a island
    if (x < 0 || y < 0 || y >= grid.size() || x >= grid[0].size() ||
        grid[x][y] != 1)
      return; // exit and not proceed

    // mark the cell as it is an island
    grid[x][y] = 2;
    q.emplace(x, y);
    dfs(q, grid, x - 1, y); // move left
    dfs(q, grid, x, y - 1); // move up
    dfs(q, grid, x + 1, y); // move right
    dfs(q, grid, x, y + 1); // move down
  }
  int shortestBridge(vector<vector<int>> &grid)
  {
    bool found = false;

    for (int i = 0; i < grid.size() && !found; i++)
    {
      for (int j = 0; j < grid[0].size() && !found; j++)
      {
        if (grid[i][j])
        {
          dfs(q, grid, i, j);
          found = true;
        }
      }
    }

    // bfs to find the shortest path
    int steps = 0;
    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    while (!q.empty())
    {
      int s = q.size();
      while (s--)
      {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 4 directions
        for (int k = 0; k < 4; k++)
        {
          int tx = x + dirs[k][0];
          int ty = y + dirs[k][1];
          if (tx < 0 || ty < 0 || tx >= grid[0].size() || ty >= grid.size() ||
              grid[tx][ty] == 2)
            continue;
          if (grid[tx][ty] == 1)
            return steps;
          // mark all the adjance cells
          grid[tx][ty] = 2;
          q.emplace(tx, ty);
        }
      }
      steps++;
    }
    return 0;
  }
};

int main() { cout << "Done!"; }