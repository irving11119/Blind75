#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int start = 0;
        int end = 0;
        int i = 0;

        while (i < intervals.size() && newInterval[0] > intervals[i][1])
        {
            i++;
        }

        start = i;

        while (i < intervals.size() && newInterval[1] >= intervals[i][0])
        {
            i++;
        }

        end = i;

        /** Start and End could be improved using binary search to improve efficiency*/

        vector<vector<int>> result;
        for (long j = 0; j < start; j++)
        {
            vector<int> insertInterval(2);
            insertInterval[0] = intervals[j][0];
            insertInterval[1] = intervals[j][1];

            result.push_back(insertInterval);
        }

        if (start == end)
        {
            vector<int> insertInterval(2);
            insertInterval[0] = newInterval[0];
            insertInterval[1] = newInterval[1];
            result.push_back(insertInterval);
        }
        else
        {
            vector<int> mergeInterval(2);
            mergeInterval[0] = min(newInterval[0], intervals[start][0]);
            mergeInterval[1] = max(newInterval[1], intervals[end - 1][1]);
            result.push_back(mergeInterval);
        }

        for (long k = end + 1; k < intervals.size(); k++)
        {
            vector<int> insertInterval(2);
            insertInterval[0] = intervals[k][0];
            insertInterval[1] = intervals[k][1];

            result.push_back(insertInterval);
        }

        return result;
    }
};