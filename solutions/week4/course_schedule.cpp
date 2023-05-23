#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasCycle(int course, vector<vector<int>> &AL, vector<int> &visited)
    {
        visited[course] = 1;
        for (auto next : AL[course])
        {
            if (visited[next] == 1)
            {
                return true;
            }

            if (visited[next] == 0)
            {
                if (hasCycle(next, AL, visited))
                {
                    return true;
                }
            }
        }

        visited[course] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> AL(numCourses);
        vector<int> visited(numCourses, 0);
        for (auto &p : prerequisites)
        {
            AL[p[1]].push_back(p[0]);
        }

        for (long i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (hasCycle(i, AL, visited))
                {
                    return false;
                }
            }
        }

        return true;
    }
};