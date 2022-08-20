
ListNode* swapNodes(ListNode* head, int k) {
    //Swap kth node from the end and kth node from the beginning
    ListNode* first = new ListNode();
    first -> next = head;
    for(int i = 0; i < k; i++) {
        first = first -> next;
    }
        
    ListNode* temp = new ListNode();
    temp -> next = head;
    ListNode* fast = temp;
    ListNode* last = temp;
    for(int i = 0; i < k; i++) {
        fast = fast -> next;
    }
    /************IMP****************/
    while(fast -> next != NULL) {
        fast = fast -> next;
        last = last -> next;
    }
    last = last -> next;
    cout << first -> val << " " << last -> val << endl;
    swap(first -> val, last -> val);
        
    return head;
}