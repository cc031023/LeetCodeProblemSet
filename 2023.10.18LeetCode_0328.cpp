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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* now = head;
        ListNode* pre = head->next;
        ListNode* cur = head->next->next;
        while (cur && cur->next) {
            ListNode* next = cur->next->next;
            ListNode* oldnext = now->next;
            now->next = cur;
            pre->next = cur->next;
            pre = cur->next;
            cur->next = oldnext;

            now = cur;
            cur = next;
        }

        if (cur) {
            ListNode* oldnext = now->next;
            now->next = cur;
            pre->next = cur->next;
            cur->next = oldnext;
        }

        return head;
    }
};