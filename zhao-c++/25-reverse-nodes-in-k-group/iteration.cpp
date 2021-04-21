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
    pair<ListNode*, ListNode*> partReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;

        while (prev != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;

        ListNode* pre = hair;

        while (head != nullptr) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (tail == nullptr) {
                    return hair->next;
                }
            }
            tie(head, tail) = partReverse(head, tail);
            pre->next = head;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
