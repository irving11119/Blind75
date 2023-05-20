#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        unordered_set<string> s = {"+", "-", "/", "*"};

        for (auto token : tokens)
        {
            if (s.find(token) == s.end())
            {
                int num = stoi(token);
                st.push(num);
            }
            else
            {
                if (token == "+")
                {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();

                    st.push(num1 + num2);
                }
                else if (token == "-")
                {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();

                    st.push(num2 - num1);
                }
                else if (token == "/")
                {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();

                    st.push(num2 / num1);
                }
                else
                {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();

                    st.push(num1 * num2);
                }
            }
        }

        return st.top();
    }
};