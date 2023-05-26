#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> direction = {0, 1, 0, -1, 0};

    int orangesRotting(vector<vector<int>> &grid)
    {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        int size;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty())
        {
            bool isRotten = false;
            size = q.size();

            for (long i = 0; i < size; i++)
            {
                auto [u, v] = q.front();
                q.pop();

                for (long k = 0; k < 4; k++)
                {
                    int nu, nv;
                    nu = u + direction[k];
                    nv = v + direction[k + 1];

                    if (nu < 0 || nu >= m || nv < 0 || nv >= n || grid[nu][nv] != 1)
                    {
                        continue;
                    }

                    isRotten = true;
                    grid[nu][nv] = 2;
                    q.emplace(nu, nv);
                }
            }

            if (isRotten)
            {
                count++;
            }
        }

        for (long i = 0; i < m; i++)
        {
            for (long j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return count;
    }
};