//
// Created by Ole on 2021/3/27 0027.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* createListNode(int *array,int size)
{
    ListNode *head = new ListNode(array[0]);
    ListNode *t = head;
    for(int i=1;i<size;i++) {
        t->next = new ListNode(array[i]);
        t = t->next;
    }
    return head;
}
void printListNode(ListNode *h)
{
    if(!h)
        return;
    cout << h->val;
    h= h->next;
    while(h) {
        cout << "->"<<h->val;
        h = h->next;
    }
    cout<<endl;
}
void printListNode(string s,ListNode *h)
{
    cout<<s;
    printListNode(h);
}


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* r = head;
        for(int i=0;i<k;i++) {
            if (r->next)
                r = r->next;
            else return head;
        }
        reverseLN(head,r);
        reverseKGroup(r,k);
        return head;
    }
    ListNode* reverseLN(ListNode* head,ListNode* end)
    {
        ListNode* t = head;
        ListNode* t2 = head;
        t->next=end->next;
        end->next = head;
        while(t2->next!=end)
        {
            t2->next->next
        }
        return
    }
    ListNode* reverse(ListNode* head,ListNode* end)
    {

    }
};

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    Solution s;
    ListNode();
    vector<ListNode*>p;
    printListNode(s.reverseKGroup(createListNode(a,10),3));
    return 1;
}