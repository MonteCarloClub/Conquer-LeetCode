//
// Created by Ole on 2021/3/27 0027.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head,*l3,*t;
        if(l1->val>l2->val) {
            l3 = head = l2;
            l2 = l2->next;
            if(!l2) {
                l3->next=l1;
                return head;
            }
        }
        else {
            l3 = head = l1;
            l1 = l1->next;
            if(!l1) {
                l3->next=l2;
                return head;
            }
        }
        while(l1&&l2)
        {
            if(l1->val>l2->val) {
                l3->next = l2;
                if(l2->next== nullptr)
                {
                    l3 = l3->next;
                    l3->next = l1;
                    return head;
                }
                l2 = l2->next;
            }
            else
            {
                l3->next = l1;
                if(l1->next== nullptr)
                {
                    l3 = l3->next;
                    l3->next = l2;
                    return head;
                }
                l1 = l1->next;
            }
            l3 = l3->next;
        }
        return head;
    }
};
int main()
{
    int a[1] = {1};
    int b[1] = {2};
    Solution s;
    ListNode();
    printListNode(s.mergeTwoLists(createListNode(a,1),createListNode(b,1)));
    return 1;
}
