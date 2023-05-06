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
    void checkHeight(TreeNode *node, int &depth, bool &ans)
    {
        if (!node || !ans)
        {
            return;
        }

        int l = 0;
        int r = 0;

        // recursively checks both child nodes
        checkHeight(node->left, l, ans);
        checkHeight(node->right, r, ans);

        // update depth by 1
        depth = max(l, r) + 1;

        // check balance
        if (abs(l - r) > 1)
        {
            ans = false;
        }
    }

    bool isBalanced(TreeNode *root)
    {
        int depth = 0;
        bool ans = true;

        checkHeight(root, depth, ans);
        return ans;
    }
};