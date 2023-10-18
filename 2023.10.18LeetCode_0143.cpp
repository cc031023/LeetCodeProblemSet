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
private:
    unordered_map<ListNode*, ListNode*> pre;

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* phead = new ListNode(-1);
        phead->next = head;

        ListNode* now = head;
        ListNode* p = phead;

        stack<ListNode*> st;
        while (head) {
            st.push(head);
            pre[head] = p;
            p = head;
            head = head->next;
        }
        int t = (st.size() + 1) / 2 - 1;

        while (t--) {
            ListNode* cur = st.top();
            st.pop();
            ListNode* next = now->next;
            now->next = cur;
            pre[cur]->next = nullptr;
            pre[cur] = now;
            cur->next = next;
            pre[next] = cur;
            now = next;
        }
    }
};