#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void fill(vector<vector<int>> &image, int sr, int sc, int color, int prev_color)
    {
        if (sr < 0 || sr > image.size() - 1)
        {
            return;
        }

        if (sc < 0 || sc > image[sr].size() - 1)
        {
            return;
        }

        if (image[sr][sc] != prev_color)
        {
            return;
        }

        if (image[sr][sc] == color)
        {
            return;
        }

        image[sr][sc] = color;

        fill(image, sr - 1, sc, color, prev_color);
        fill(image, sr + 1, sc, color, prev_color);
        fill(image, sr, sc + 1, color, prev_color);
        fill(image, sr, sc - 1, color, prev_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        fill(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};