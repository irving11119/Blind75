#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> hm;
        unordered_map<char, int> hm1;

        for (long i = 0; i < s.size(); i++)
        {
            auto itr = hm.find(s[i]);
            if (itr == hm.end())
            {
                hm.insert({s[i], 1});
            }
            else
            {
                itr->second++;
            }
        }

        for (long i = 0; i < t.size(); i++)
        {
            auto itr1 = hm1.find(t[i]);
            if (itr1 == hm1.end())
            {
                hm1.insert({s[i], 1});
            }
            else
            {
                itr1->second++;
            }
        }

        return hm == hm1;
    }
};