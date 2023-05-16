// 1.原地构造.
class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* now = head;
        // 复制节点.
        while (now != nullptr) {
            Node* temp = now->next;
            now->next = new Node(now->val);
            now->next->next = temp;
            now = temp;
        }
        now = head;
        // 复制随机节点.
        while (now != nullptr) {
            if (now->random != nullptr)
                now->next->random = now->random->next;
            now = now->next->next;
        }
        now = head;
        // 把节点串分离.
        Node *ans = head->next, *cur = ans;
        while (cur->next != nullptr) {
            now->next = now->next->next;
            cur->next = cur->next->next;
            now = now->next;
            cur = cur->next;
        }
        now->next = nullptr;
        return ans;
    }
};

// 2.哈希遍历存地址.

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> mp;
        while (cur != nullptr) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};