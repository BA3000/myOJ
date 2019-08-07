class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index >= size){
            return -1;
        }
        Node *cur = head;
        for(int i=0; i<index; i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newhead = new Node(val, head);
        head = newhead;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *tail = new Node(val, NULL);
        Node *cur = head;
        while(cur->next)cur = cur->next;
        cur->next = tail;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size){
            return;
        }
        if(index==0||index==-1){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node *cur = head;
        for(int i=0; i<index-1; i++){
            cur = cur->next;
        }
        Node *toAdd = new Node(val, cur->next);
        cur->next = toAdd;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index >= size) return;
        Node *cur = head;
        if(index == 0){
            head = head->next;
            size--;
            delete cur;
            return;
        }
        for(int i=0; i<index-1; i++){
            cur = cur->next;
        }
        Node *toFree = cur->next;
        cur->next = cur->next->next;
        delete toFree;
        size--;
    }

private:
    struct Node{
        int val;
        Node *next;
        Node(int x, Node *n): val(x), next(n) {};
    };
    Node *head;
    int size;
};