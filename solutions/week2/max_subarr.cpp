#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ptr1 = 0;
        int ptr2 = 0;
        int sum = 0;
        int max_sum = INT_MIN;

        while (ptr2 < nums.size())
        {
            if (sum < 0 && nums[ptr2] >= sum)
            {
                sum = 0;
                ptr1 = ptr2;
            }

            sum += nums[ptr2];
            max_sum = max(sum, max_sum);

            ptr2++;
        }

        return max_sum;
    }
};