#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        map<Node *, Node *> m;

        // use a map to store the original node as key and new cloned node as value
        Node *head = new Node(node->val);
        m[node] = head;

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            // set up a currently pointer
            Node *curr = q.front();
            q.pop();

            for (auto x : curr->neighbors)
            {
                if (m.find(x) == m.end())
                {
                    Node *b = new Node(x->val);
                    m[x] = b;
                    q.push(x);
                }

                // link the duplicated
                m[curr]->neighbors.push_back(m[x]);
            }
        }
        return m[node];
    }
};

int main() { cout << "done!"; }