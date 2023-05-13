#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int solve(TreeNode *curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }

        int left = solve(curr->left);
        int right = solve(curr->right);

        int length;
        length = max(left, right) + 1;

        return length;
    }

    int maxDepth(TreeNode *root)
    {
        return solve(root);
    }
};