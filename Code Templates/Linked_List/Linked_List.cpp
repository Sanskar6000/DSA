class ListNode {
    private:
    int val;
    ListNode* next;

    public:
    ListNode(int val) {
        this -> val = val;
        this -> next = NULL;
    }
};

//Doubly Linked List
class ListNode {
    private:
    int val;
    ListNode* next;
    ListNode* prev;

    public:
    ListNode(int val) {
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};