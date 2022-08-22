//Tortoise Method
ListNode* middleNode(ListNode* head) {
        // Tortoise Method
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL) {
            cout << " Yes " << endl;
            fast = fast -> next -> next;
            head = head -> next;
        }
        return head;
}