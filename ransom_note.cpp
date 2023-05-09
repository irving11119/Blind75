#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {

        char key;
        unordered_map<char, int> hm;
        for (long i = 0; i < magazine.size(); i++)
        {
            auto itr = hm.find(magazine[i]);

            if (itr == hm.end())
            {
                hm.insert({magazine[i], 1});
            }
            else
            {
                itr->second++;
            }
        }

        for (long j = 0; j < ransomNote.size(); j++)
        {
            auto itr = hm.find(ransomNote[j]);

            if (itr == hm.end())
            {
                return false;
            }
            else
            {
                itr->second--;

                if (itr->second < 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};