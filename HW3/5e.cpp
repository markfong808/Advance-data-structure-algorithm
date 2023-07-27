#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited,
             string word, int i, int j, int start)
    {
        // row count how many
        int rows = board.size();
        // column count how many
        int columns = board[0].size();
        // base case if the current position equals to the length of word
        if (start == word.size())
            return true;
        // out of bounds,the char in the word is not inside the board and
        // the path is visited
        if (i < 0 || j < 0 || i >= rows || j >= columns ||
            word[start] != board[i][j] || visited[i][j])
            return false;

        // mark cell as visited
        visited[i][j] = true;

        // recursive dfs on adjancce cells // recursion only once, if it works
        bool result =
            dfs(board, visited, word, i + 1, j, start + 1) || // move down
            dfs(board, visited, word, i - 1, j, start + 1) || // move up
            dfs(board, visited, word, i, j + 1, start + 1) || // move right
            dfs(board, visited, word, i, j - 1, start + 1);   // move left
        // Unmark cell after backtracking
        visited[i][j] = false;

        return result;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int columns = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(columns, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (dfs(board, visited, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

int main() { cout << "done!"; }