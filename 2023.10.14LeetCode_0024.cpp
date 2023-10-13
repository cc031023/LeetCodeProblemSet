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
    ListNode* swapPairs(ListNode* head) {
        ListNode* phead = new ListNode(-1);
        phead->next = head;
        ListNode* temp = phead;
        while (temp->next && temp->next->next) {
            ListNode* pre = temp->next;
            ListNode* now = temp->next->next;

            temp->next = now;
            pre->next = now->next;
            now->next = pre;

            temp = temp->next->next;
        }

        ListNode* ans = phead->next;
        delete phead;

        return ans;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return head; }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};
