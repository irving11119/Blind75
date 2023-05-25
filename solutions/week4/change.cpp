#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<long> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for (long i = 0; i < dp.size(); i++)
        {
            for (long j = 0; j < coins.size(); j++)
            {
                long index = coins[j];
                if (i - index < 0 || dp[i - index] == INT_MAX)
                {
                    continue;
                }

                dp[i] = min(dp[i], dp[i - index] + 1);
            }
        }

        if (dp[amount] == INT_MAX)
        {
            return -1;
        }

        return dp[amount];
    }
};