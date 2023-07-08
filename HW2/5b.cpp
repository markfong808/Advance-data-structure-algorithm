#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());

        // if (target == "0000") return -1;

        queue<string> q;
        q.push("0000");

        int level = 0; // each turn

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                string currlock = q.front();
                q.pop();

                if (currlock == target)
                    return level;

                if (deadSet.find(currlock) != deadSet.end())
                    continue;
                deadSet.insert(currlock);

                for (int i = 0; i < 4; i++)
                {
                    string temp = currlock;
                    int updigit = currlock[i] - '0' + 1;
                    int downdigit = currlock[i] - '0' - 1;

                    // if downdigit is negative int, Ex: 0 - 1 = -1
                    if (downdigit < 0)
                        downdigit += 10;

                    // if updigit is 9 , Ex: 9 + 1 = 10 , 10 mod 10 will return back to 0
                    updigit = updigit % 10;
                    downdigit = downdigit % 10;

                    // temp was "0000", temp is now "1000"
                    temp[i] = static_cast<char>(updigit + '0');
                    q.push(temp); // push "1000" into the queue

                    // temp was "0000", temp is now "9000"
                    temp[i] = static_cast<char>(downdigit + '0');
                    q.push(temp); // push "9000" into the queue
                }
            }
            level++; // move down to second level
        }
        return -1;
    }
};
int main() { cout << "Done!\n"; }