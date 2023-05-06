#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // can be improved with Floyd Cycle Algorithm
    bool hasCycle(ListNode *head)
    {
        ListNode *curr = head;

        unordered_set<ListNode *> s;

        while (curr)
        {
            auto itr = s.find(curr);

            if (itr == s.end())
            {
                s.insert(curr);
            }
            else
            {
                return true;
            }

            curr = curr->next;
        }

        return false;
    }
};