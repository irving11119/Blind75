#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> arr(nums.size());

        for (long i = 0; i < nums.size(); i++)
        {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        int ptr1 = 0;
        int ptr2 = arr.size() - 1;
        vector<int> result;
        while (ptr1 < ptr2)
        {
            if (arr[ptr1].first + arr[ptr2].first < target)
            {
                ptr1++;
            }
            else if (arr[ptr1].first + arr[ptr2].first > target)
            {
                ptr2--;
            }
            else
            {
                result.push_back(arr[ptr1].second);
                result.push_back(arr[ptr2].second);
                return result;
            }
        }

        return result;
    }
};