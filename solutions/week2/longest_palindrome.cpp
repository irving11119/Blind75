#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_set<char> hm;
        int longest = 0;
        for (long i = 0; i < s.size(); i++)
        {
            auto itr = hm.find(s[i]);
            if (itr == hm.end())
            {
                hm.insert(s[i]);
            }
            else
            {
                longest += 2;
                hm.erase(itr);
            }
        }

        if (hm.size() > 0)
        {
            longest++;
        }

        return longest;
    }
};