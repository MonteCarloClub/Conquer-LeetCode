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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int min = INT_MAX;
        ListNode *head = new ListNode(INT_MIN);
        ListNode *r = head;
        int t=0;
        while (1) {
            int flag = 1;
            min = INT_MAX;
            for (ListNode *l:lists)
                if (l)
                    flag = 0;
            if(flag)break;
            for (int i=0;i<lists.size();i++) {
                ListNode *l = lists[i];
                if (l && l->val <= min) {
                    t = i;
                    min = l->val;
                }
            }
            lists[t]= lists[t]->next;
            r->next = new ListNode(min);
            r = r->next;
        }
        return head->next;
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
