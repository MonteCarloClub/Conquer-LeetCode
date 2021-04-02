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
    ListNode* swapPairs(ListNode* head) {
        if(head== nullptr)
            return nullptr;
        return reverseKGroup(head,2);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* r = head;
        if(k==1)
            return head;
        for(int i=0;i<k-1;i++) {
            if (r->next)
                r = r->next;
            else return head;
        }
        reverseLN(head,r);
        if(head->next)
            head->next = reverseKGroup(head->next,k);
        return r;
    }
    ListNode* reverseLN(ListNode* head,ListNode* end)
    {
        stack<ListNode*>s;
        ListNode* t = head;
        while(t!=end) {
            s.push(t);
            t= t->next;
        }
        head->next = end->next;
        while(!s.empty())
        {
            t->next = s.top();
            s.pop();
            t = t->next;
        }
        return end;
    }
};

int main()
{
    int a[10] = {1,2};
    Solution s;
    ListNode();
    vector<ListNode*>p;
    printListNode(s.reverseKGroup(createListNode(a,2),2));
    return 1;
}