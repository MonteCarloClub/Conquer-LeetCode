//
// Created by Ole on 2021/3/23 0023.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0,s=0;

        ListNode* lt = new ListNode();
        lt->next =  new ListNode();
        ListNode* lr = lt->next;
        while(1)
        {
            if(l1->next&&l2->next==0)
                l2->next = new ListNode(0);
            if(l2->next&&l1->next==0)
                l1->next = new ListNode(0);
            c = (l1->val+l2->val+lt->next->val)/10;
            s = (l1->val+l2->val+lt->next->val)%10;
            lt->next->val = s;
            lt->next->next = new ListNode(c);
            if(l1->next==0&&l2->next==0)
            {
                if(lt->next->next->val==0)
                    lt->next->next = 0;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
            lt = lt->next;
        }
        return lr;
    }
};