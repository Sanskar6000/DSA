//Calculate Length of list
//Make a circle
//Brute

ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head -> next == NULL || k == 0) return head;
        //Find len of list
        int len = 1;
        ListNode* tail = head;
        while(tail -> next != NULL) {
            len++;
            tail = tail -> next;
        }
        
        //Form a Circle
        tail -> next = head;
        
        
        //rth node from last will be head and last node will point to head
        int r = k % len; 
        for(int i = 0; i < len - r; i++) {
            tail = tail -> next;
        }
        //Changing head (Easy AF)
        head = tail -> next;
        tail -> next = NULL;
        
        return head;
    }