#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int find_max(int x, int y)
    {
        if (x >= y)
        {
            return x;
        }

        return y;
    }

    int find_min(int x, int y)
    {
        if (x <= y)
        {
            return x;
        }

        return y;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ancestor = root;
        int max = find_max(p->val, q->val);
        int min = find_min(p->val, q->val);

        while (ancestor)
        {
            if (ancestor->val < min)
            {
                ancestor = ancestor->right;
            }
            else if (ancestor->val > max)
            {
                ancestor = ancestor->left;
            }
            else
            {
                return ancestor;
            }
        }

        return nullptr;
    }
};