#include <bits/stdc++.h>
using namespace std;

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
        unordered_map<Node *, Node *> hm;
        queue<Node *> q;

        if (!node)
        {
            return node;
        }

        q.push(node);

        Node *source = new Node(node->val);
        hm[node] = source;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            for (auto neighbours : curr->neighbors)
            {
                if (hm.find(neighbours) == hm.end())
                {
                    hm[neighbours] = new Node(neighbours->val);
                    q.push(neighbours);
                }

                hm[curr]->neighbors.push_back(hm[neighbours]);
            }
        }

        return hm[node];
    }
};