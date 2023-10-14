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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode* phead = new ListNode(-1);
        phead->next = head;
        ListNode* mid = nullptr;
        ListNode* midpre = nullptr;
        ListNode* pre = phead;
        while (head) {
            if (!mid && head->val >= x) {
                mid = head;
                midpre = pre;
            }

            if (mid && head->val < x) {
                pre->next = head->next;
                head->next = mid;
                midpre->next = head;
                midpre = head;
            }
            pre = head;
            head = head->next;
        }
        ListNode* ans = phead->next;
        delete phead;
        return ans;
    }
};