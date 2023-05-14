#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;

        for (long i = 0; i < nums.size(); i++)
        {
            auto itr = s.find(nums[i]);

            if (itr == s.end())
            {
                s.insert(nums[i]);
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};