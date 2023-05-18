#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hm;
        int left_ptr = 0;
        int right_ptr = 0;
        int max_len = 0;

        while (right_ptr < s.size())
        {
            auto itr = hm.find(s[right_ptr]);

            if (itr == hm.end())
            {
                hm.insert(s[right_ptr]);

                max_len = max(max_len, (right_ptr - left_ptr + 1));
            }
            else
            {
                while (s[left_ptr] != s[right_ptr])
                {
                    hm.erase(s[left_ptr++]);
                }
                left_ptr++;
            }

            right_ptr++;
        }

        return max_len;
    }
};