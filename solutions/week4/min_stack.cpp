#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st;

    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            int min_val = val;
            st.push({val, min_val});
        }
        else
        {
            int min_val = min(st.top().second, min_val);
            st.push({val, min_val});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        int val = st.top().first;
        return val;
    }

    int getMin()
    {
        int val = st.top().second;
        return val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */