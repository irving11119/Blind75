#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> direction = {0, 1, 0, -1, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // Run BFS and update distance.
        int m, n;

        m = mat.size();
        n = mat[0].size();
        queue<pair<int, int>> q;
        for (long i = 0; i < m; i++)
        {
            for (long j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    // find all 0s and set them as a source to find closest non 0
                    q.emplace(i, j);
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            auto [u, v] = q.front();
            q.pop();

            // faster way of searching nsew
            for (long i = 0; i < 4; i++)
            {
                int nu, nv;
                nu = u + direction[i];
                nv = v + direction[i + 1];

                if (nu < 0 || nu >= m || nv < 0 || nv >= n || mat[nu][nv] != -1)
                {
                    continue;
                }

                mat[nu][nv] = mat[u][v] + 1;
                q.emplace(nu, nv);
            }
        }

        return mat;
    }
};