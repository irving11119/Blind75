#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> product(nums.size());
        int sum = nums[0];
        bool has_zero = (sum == 0);

        int zero_count;

        if (has_zero)
        {
            zero_count = 1;
            sum = 1;
        }
        else
        {
            zero_count = 0;
        }

        for (long i = 1; i < nums.size(); i++)
        {
            int num = nums[i];

            if (num == 0)
            {
                has_zero = true;
                zero_count++;
                continue;
            }

            sum *= num;
        }

        for (long i = 0; i < product.size(); i++)
        {
            if (!has_zero)
            {
                product[i] = sum / nums[i];
            }
            else
            {
                if (nums[i] == 0)
                {
                    if (zero_count > 1)
                    {
                        product[i] = 0;
                    }
                    else
                    {
                        product[i] = sum;
                    }
                }
                else
                {
                    product[i] = 0;
                }
            }
        }
        return product;
    }
};