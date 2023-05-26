#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> direction = {0, 1, 0, -1, 0};

    int numIslands(vector<vector<char>> &grid)
    {
        int num = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (long i = 0; i < m; i++)
        {
            for (long j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {

                        auto [u, v] = q.front();
                        q.pop();

                        for (long k = 0; k < 4; k++)
                        {
                            int nu, nv;
                            nu = u + direction[k];
                            nv = v + direction[k + 1];

                            if (nu < 0 || nu >= m || nv < 0 || nv >= n || grid[nu][nv] != '1')
                            {
                                continue;
                            }

                            grid[nu][nv] = '0';
                            q.emplace(nu, nv);
                        }
                    }
                }
            }
        }

        return num;
    }
};