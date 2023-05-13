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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;

        while (fast_ptr && fast_ptr->next)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }

        return slow_ptr;
    }
};