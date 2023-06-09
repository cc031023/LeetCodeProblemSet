// 迭代.
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *now = head;
        ListNode *pre = nullptr;
        while (now != nullptr)
        {
            ListNode *node = now->next;
            now->next = pre;
            pre = now;
            now = node;
        }
        return pre;
    }
};
// 递归.
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *now = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return now;
    }
};
// 神奇双指针
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *now = head;
        while (head->next)
        {
            ListNode *node = head->next->next;
            head->next->next = now;
            now = head->next;
            head->next = node;
        }
        return now;
    }
};