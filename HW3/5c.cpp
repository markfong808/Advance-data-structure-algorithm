#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    // BFS
    void bfs(int row, int col, vector<vector<int>> &visited,
             vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // mark as visited
        visited[row][col] = 1;
        // pair represents the coordinates of a cell in the grid
        queue<pair<int, int>> q;
        q.push({row, col}); // enqueue the starting point
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traversing all the neighbours of {row,col}
            //  {-1,0,1}
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (abs(x) + abs(y) == 2)
                        continue;          // skip and continue for diagonal neighours
                    int new_row = row + x; // 0 + (-1) = -1
                    int new_col = col + y; // 0 + 0 = 0
                    // base case for out of bound
                    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                        !visited[new_row][new_col] && grid[new_row][new_col] == '1')
                    {
                        visited[new_row][new_col] = 1;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int island = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, visited, grid);
                    // once the queue got empty, that means we found  all possible pieces
                    // of land, so increment number
                    island++;
                }
            }
        }
        return island;
    }
};

int main() { cout << "done!"; }