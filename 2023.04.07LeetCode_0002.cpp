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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *now = new ListNode;
        ListNode *head = now;
        ListNode *next;
        int x = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            next = new ListNode;
            if (l1 != nullptr && l2 == nullptr)
            {
                now->val = (l1->val + x) % 10;
                x = (l1->val + x) / 10;
            }
            else if (l1 == nullptr && l2 != nullptr)
            {
                now->val = (l2->val + x) % 10;
                x = (l2->val + x) / 10;
            }
            else
            {
                now->val = (l1->val + l2->val + x) % 10;
                x = (l1->val + l2->val + x) / 10;
            }
            next = new ListNode;
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
            if (l1 != nullptr || l2 != nullptr)
            {
                now->next = next;
                now = next;
            }
            else
            {
                if (!x)
                {
                    break;
                }
                else
                {
                    now->next = next;
                    now = next;
                    now->val = x;
                    return head;
                }
            }
        }
        return head;
    }
};