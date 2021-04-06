/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto ptrA = headA;
        auto ptrB = headB;
        int flag = 0;
        while(true) {
            if (ptrA == ptrB) {
                return ptrB;
            } else if (ptrA == nullptr && flag == 2) {
                return nullptr;
            } else {
                ptrA = ptrA->next;
                ptrB = ptrB->next;
                if (ptrA == nullptr && flag < 2) {
                    ptrA = headB;
                    flag++;
                }
                if (ptrB == nullptr && flag < 2) {
                    ptrB = headA;
                    flag++;
                }
            }
        }
    }
};
