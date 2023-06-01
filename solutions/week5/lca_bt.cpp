#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    bool dfs(TreeNode* curr, TreeNode* target, vector<TreeNode*>& path) {
        if (!curr) {
            return false;
        }

        path.push_back(curr);

        if (curr == target) {
            return true;
        }

        if (dfs(curr->left, target, path) || dfs(curr->right, target, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        dfs(curr, p, path1);
        dfs(curr, q, path2);

        int index = 0;
        TreeNode* ancestor;
        while (index < path1.size() && index < path2.size()) {
            if (path1[index] == path2[index]) {
                ancestor = path1[index];
            } else {
                return ancestor;
            }
        }

        return ancestor;
    }
};