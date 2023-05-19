#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        set<vector<int>> s;

        for (long i = 0; i < nums.size(); i++)
        {

            if (nums[i] > 0)
            {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int num1 = nums[i];
            int left_ptr = i + 1;
            int right_ptr = nums.size() - 1;
            int target = 0;

            while (left_ptr < right_ptr)
            {
                int total = nums[left_ptr] + nums[right_ptr] + num1;

                if (total == target)
                {
                    vector<int> result = {num1, nums[left_ptr],
                                          nums[right_ptr]};
                    auto itr = s.find(result);
                    s.insert(result);
                    left_ptr++;
                    right_ptr--;
                }
                else if (total < target)
                {
                    left_ptr++;
                }
                else
                {
                    right_ptr--;
                }
            }
        }

        for (auto trips : s)
        {
            output.push_back(trips);
        }

        return output;
    }
};