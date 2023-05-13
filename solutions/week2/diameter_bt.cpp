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
    int solve(TreeNode *curr, int &max_len)
    {
        if (curr == nullptr)
        {
            return -1;
        }

        int left = solve(curr->left, max_len);
        int right = solve(curr->right, max_len);

        int length;
        length = max(left, right) + 1;

        if (left + right + 2 > max_len)
        {
            max_len = left + right + 2;
        }

        return length;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int max = -1;
        return solve(root, max);
    }
};