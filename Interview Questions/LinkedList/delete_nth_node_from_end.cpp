//fast and slow will start from previous pointer to head
//Fast will move first n nodes
//hence slow will move first size - n nodes
//Return new_pointer's next not head

ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) return NULL;
        
        ListNode* temp = new ListNode();
        temp -> next = head;
        ListNode* fast = temp;
        ListNode *slow = temp;
        for(int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        
        while(fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        slow -> next = slow -> next -> next;
       
        //Do not return head
        return temp -> next;
    }