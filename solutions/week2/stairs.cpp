#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    vector<int> arr(n, INT_MAX);
    arr[0] = 1;

    if (n > 1)
    {
        arr[1] = 1;
    }

    for (long i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            arr[i + 1] += arr[i] + 1;
        }

        if (i < n - 2)
        {
            arr[i + 2] += arr[i] + 1;
        }
    }

    return arr[n - 1];
}