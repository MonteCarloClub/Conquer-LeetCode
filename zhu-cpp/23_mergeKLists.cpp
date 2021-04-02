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
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        int min = INT_MAX;
//        ListNode *head = new ListNode(INT_MIN);
//        ListNode *r = head;
//        int t=0;
//        while (1) {
//            int flag = 1;
//            min = INT_MAX;
//            for (ListNode *l:lists)
//                if (l)
//                    flag = 0;
//            if(flag)break;
//            for (int i=0;i<lists.size();i++) {
//                ListNode *l = lists[i];
//                if (l && l->val <= min) {
//                    t = i;
//                    min = l->val;
//                }
//            }
//            lists[t]= lists[t]->next;
//            r->next = new ListNode(min);
//            r = r->next;
//        }
//        return head->next;
//    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s=0, e = lists.size()-1;
        if(~e)
            return nullptr;
        if(!e)
            return lists[0];
        int times = 0;
        while(e)
        {
            e>>=1;
            times++;
        }
        for(int i=0;i<times;i++)
        {
            int size = lists.size();
            for(int i=0;i<=size-2;i+=2) {
                ListNode *t1 = lists[0], *t2 = lists[1];
                lists.erase(lists.begin());
                lists.erase(lists.begin());
                lists.push_back(mergeTwoLists(t1, t2));
            }
        }
        return lists[0];
    }
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
    int b[2] = {2,2};
    int c[3] = {1,2,3};
    Solution s;
    ListNode();
    vector<ListNode*>p;
    p.push_back(createListNode(a,1));
    p.push_back(createListNode(b,2));
    p.push_back(createListNode(c,3));
    printListNode(s.mergeKLists(p));
    return 1;
}
