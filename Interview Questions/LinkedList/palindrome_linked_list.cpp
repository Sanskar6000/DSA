//move fast and slow pointer
//reverse the right half part 
bool isPalindrome(ListNode* head) {
        //Slow and fast pointers
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* slow = dummy, *fast = dummy;
        
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //Reverse the right half of linked list
        ListNode* prev = NULL, *curr, *nxt = NULL;
        
        if(fast -> next == NULL) curr = slow -> next;
        else curr = slow -> next -> next;
        
        while(curr) {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        slow -> next = prev;
        
        //Checking for palindrome
        slow = slow -> next;
        while(slow) {
            if(slow -> val != head -> val) return false;
            head = head -> next;
            slow = slow -> next;
        }
        
        return true;
}