// 第一次自己写的乱七八糟
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *now = head;
        while (now->next != nullptr)
        {
            while (now->val == now->next->val)
            {
                ListNode *node = now->next;
                if (now->next->next == nullptr)
                {
                    now->next = nullptr;
                    delete node;
                    return head;
                }
                now->next = now->next->next;
                delete node;
            }
            now = now->next;
        }
        return head;
    }
};
// 正常写的
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *now = head;
        while (now->next)
        {
            if (now->val == now->next->val)
                now->next = now->next->next;
            else
                now = now->next;
        }
        return head;
    }
};
// 递归写法
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};