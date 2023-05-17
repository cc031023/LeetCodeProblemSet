// 哈希.
class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> st;
        while (headA != nullptr) {
            st.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (st.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};
// 双指针迭代.
class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = p1 == nullptr ? headB : p1->next;
            p2 = p2 == nullptr ? headA : p2->next;
        }
        return p1;
    }
};