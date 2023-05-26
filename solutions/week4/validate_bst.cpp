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
    vector<int> arr;
    void inOrderTraversal(TreeNode *node)
    {
        if (!node)
        {
            return;
        }

        inOrderTraversal(node->left);

        arr.push_back(node->val);

        inOrderTraversal(node->right);
    }

    bool isValidBST(TreeNode *root)
    {
        inOrderTraversal(root);

        for (long i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] >= arr[i])
            {
                return false;
            }
        }

        return true;
    }
};
