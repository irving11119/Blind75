#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binary_search(vector<int> &nums, int start, int end, int target)
    {
        int mid = (start + end + 1) / 2;

        if (start > end)
        {
            return -1;
        }

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] < target)
        {
            return binary_search(nums, start, mid - 1, target);
        }

        return binary_search(nums, mid + 1, end, target);
    }

    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        return binary_search(nums, start, end, target);
    }
};