#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s;
    stack<int> s1;
    int current;

    MyQueue()
    {
        int current = 0;
    }

    void push(int x)
    {
        while (!s.empty())
        {
            s1.push(s.top());
            s.pop();
        }

        s.push(x);

        while (!s1.empty())
        {
            s.push(s1.top());
            s1.pop();
        }
    }

    int pop()
    {
        int top = s.top();
        s.pop();
        return top;
    }

    int peek()
    {
        int top = s.top();
        return top;
    }

    bool empty()
    {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */