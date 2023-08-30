// 快慢指针
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next) return NULL;
    struct ListNode *fast = head->next->next;
    struct ListNode *slow = head->next;
    while (slow != fast) {
        if (!fast || !fast->next) return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        unordered_set<ListNode *> st;
        while (head && st.find(head) == st.end()) {
            st.insert(head);
            head = head->next;
        }
        return head;
    }
};
