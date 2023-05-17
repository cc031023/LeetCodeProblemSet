// 1.递归逆天改人家的传参(将k改成引用).
class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int& k) {
        if (head == nullptr || k == 0 || head->next == nullptr)
            return head;
        ListNode* now = getKthFromEnd(head->next, k);
        k--;
        if (k == 1)
            return head;
        return now;
    }
};
// 2.快慢双指针.

class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && k > 0) {
            fast = fast->next;
            --k;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
