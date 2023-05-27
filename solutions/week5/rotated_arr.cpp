#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int modifiedBinarySearch(vector<int> &nums, int start, int end, int target)
    {
        if (start > end)
        {
            return -1;
        }

        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] > nums[start])
        {
            if (nums[start] <= target && nums[mid - 1] >= target)
            {
                return modifiedBinarySearch(nums, start, mid - 1, target);
            }

            return modifiedBinarySearch(nums, mid + 1, end, target);
        }

        if (nums[mid + 1] <= target && nums[end] >= target)
        {
            return modifiedBinarySearch(nums, mid + 1, end, target);
        }

        return modifiedBinarySearch(nums, 1, mid - 1, target);
    }

    int search(vector<int> &nums, int target)
    {
        return modifiedBinarySearch(nums, 0, nums.size() - 1, target);
    }
};