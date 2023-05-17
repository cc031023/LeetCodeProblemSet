// 递归.
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// 迭代.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode* ans = new ListNode(0);
        ListNode* now = ans;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                now->next = l1;
                l1 = l1->next;
            } else {
                now->next = l2;
                l2 = l2->next;
            }
            now = now->next;
        }
        now->next = l1 == nullptr ? l2 : l1;
        return ans->next;
    }
};