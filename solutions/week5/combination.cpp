#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> output;

    vector<int> solve(vector<int> &candidates, int &target, int sum, int i, vector<int> &sub)
    {
        if (i >= candidates.size())
        {
            return;
        }

        if (sum + candidates[i] == target)
        {
            sub.push_back(candidates[i]);
            output.push_back(sub);
        }

        if (sum + candidates[i] < target)
        {
            vector<int> sub1 = sub;
            vector<int> sub2 = sub;

            solve(candidates, target, sum + candidates[i], i, sub2);
            solve(candidates, target, sum, i + 1, sub1);
        }
        else
        {
            solve(candidates, target, sum, i + 1, sub);
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, 0, sub);

        return output;
    }
};