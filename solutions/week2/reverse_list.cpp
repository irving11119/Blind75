#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reverse(ListNode *&curr, ListNode *&prev, ListNode *&head)
    {
        if (curr == nullptr)
        {
            return;
        }

        reverse(curr->next, curr, head);
        curr->next = prev;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        reverse(curr, prev, head);
        return head;
    }
};