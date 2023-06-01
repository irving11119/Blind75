#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> output;

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int index = 0;
        int first = intervals[0][0];
        int second = intervals[0][1];
        for (index = 0; index < intervals.size() - 1; index++) {
            if (intervals[index][1] < intervals[index + 1][0]) {
                output.push_back(intervals[index]);
                continue;
            }

            vector<int> new_interval(2);

            intervals[index + 1][0] = intervals[index][0];
            intervals[index + 1][1] =
                max(intervals[index][1], intervals[index + 1][1]);
        }
        output.push_back(intervals[index]);
        return output;
    }
};