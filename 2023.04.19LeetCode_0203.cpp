// 递归.
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
// 迭代.
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    { // 虚拟节点下一个是head,因为head也可能符合删除条件.
        struct ListNode *dummyHead = new ListNode(0, head);
        struct ListNode *temp = dummyHead;
        while (temp->next != nullptr)
        {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return dummyHead->next;
    }
};
