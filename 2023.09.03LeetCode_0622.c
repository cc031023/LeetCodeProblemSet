typedef struct {
    struct ListNode* head;
    struct ListNode* tail;
    int size;
    int capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* newhead = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    newhead->head = newhead->tail = NULL;
    newhead->capacity = k;
    newhead->size = 0;
    return newhead;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size >= obj->capacity) return false;
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = value;
    newnode->next = NULL;
    if (!obj->head) {
        obj->head = obj->tail = newnode;
    } else {
        obj->tail->next = newnode;
        obj->tail = newnode;
    }
    ++obj->size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!obj->size) return false;
    struct ListNode* node = obj->head;
    obj->head = obj->head->next;
    --obj->size;
    free(node);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return obj->size == 0 ? -1 : obj->head->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return obj->size == 0 ? -1 : obj->tail->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return !obj->size;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    for (struct ListNode* cur = obj->head; cur;) {
        struct ListNode* node = cur;
        cur = cur->next;
        free(node);
    }
    free(obj);
}
