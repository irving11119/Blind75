#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double calculate_distance(int &x, int &y)
    {
        int sum = (x * x) + (y * y);

        return sqrt((double)sum);
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        for (long i = 0; i < points.size(); i++)
        {
            pq.push({calculate_distance(points[i][0], points[i][1]), points[i]});
        }

        vector<vector<int>> output;
        for (long j = 0; j < k; j++)
        {
            auto coord = pq.top();
            pq.pop();

            output.push_back(coord.second);
        }

        return output;
    }
};
