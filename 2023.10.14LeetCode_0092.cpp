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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;
        ListNode* phead = new ListNode(-1);
        phead->next = head;
        ListNode* pre = phead;
        for (int i = 1; i <= left - 1; ++i) {
            pre = pre->next;
        }

        ListNode* cur = pre->next;
        for (int i = 1; i <= right - left; ++i) {
            ListNode* nextnode = cur->next;
            cur->next = nextnode->next;
            nextnode->next = pre->next;
            pre->next = nextnode;
        }

        ListNode* ans = phead->next;
        delete phead;
        return ans;
    }
};