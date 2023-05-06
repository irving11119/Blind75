#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    string lower(string s)
    {
        for (long i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] - 'A' + 'a';
            }
        }

        return s;
    }

    string format(string s)
    {
        string s1;

        for (long i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                s1 += s[i];
            }
        }

        return s1;
    }
    bool isPalindrome(string s)
    {

        string s1 = format(lower(s));

        int ptr1 = 0;
        int ptr2 = s1.size() - 1;

        while (ptr1 < ptr2)
        {
            if (s1[ptr1] != s1[ptr2])
            {
                return false;
            }

            ptr1++;
            ptr2--;
        }

        return true;
    }
};