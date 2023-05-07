#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long left = 0;
        long right = n;
        long mid;
        while (left < right)
        {
            mid = (left + right) / 2;

            if (!isBadVersion(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};