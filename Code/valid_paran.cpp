#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        if (s.length() == 1)
        {
            return false;
        }

        else
        {

            for (long i = 0; i < s.size(); i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    st.push(s[i]);
                }
                else
                {
                    if (st.empty())
                    {
                        return false;
                    }

                    if (st.top() == '(' && s[i] != ')')
                    {
                        return false;
                    }
                    else if (st.top() == '[' && s[i] != ']')
                    {
                        return false;
                    }
                    else if (st.top() == '{' && s[i] != '}')
                    {
                        return false;
                    }

                    st.pop();
                }
            }
        }

        return st.empty();
    }
};