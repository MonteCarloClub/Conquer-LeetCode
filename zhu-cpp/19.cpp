//
// Created by Ole on 2021/3/27 0027.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t = head,*te = head;
        while(n--) {
            te = te->next;
            if(!te->next)
                return head->next;
        }
        te = te->next;
        while(te->next)
        {
            t = t->next;
            te = te->next;
        }
        t->next= t->next->next;
        return head;
    }
};

int main()
{
    Solution s;
    return 1;
}