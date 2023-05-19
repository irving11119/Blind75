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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> output;

        if (!root)
        {
            return output;
        }

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            while (size--)
            {
                TreeNode *curr = q.front();

                level.push_back(curr->val);
                q.pop();

                if (curr->left)
                {
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    q.push(curr->right);
                }
            }

            output.push_back(level);
        }

        return output;
    }
};