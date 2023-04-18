/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> sum;
        while (head != nullptr)
        {
            if (sum.count(head))
                return true;
            sum.insert(head);
            head = head->next;
        }
        return false;
    }
};
