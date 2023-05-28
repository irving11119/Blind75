#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> output;

    void solve(vector<int> nums, int index)
    {
        if (index == nums.size() - 1)
        {
            output.push_back(nums);
            return;
        }

        for (long i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        solve(nums, 0);
        return output;
    }
};