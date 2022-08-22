//Approach One - O(n * m)
//Approach Two -> Unordered Set
//Approach Three -> Move the two nodes simultaneously and if one of them reaches NULL. Assign this to start of another list.
//After abs(len(a) - len(b)) assignments. They will traverse at equal times
//TC (2 * max(len(a), len(b)))

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode *A = headA;
       ListNode *B = headB;
        
       while(A != B) {
           A = A -> next;
           B = B -> next;
           
           if(A == B) return A;
           
           if(A == NULL) A = headB;
           if(B == NULL) B = headA;
       }
        
        return A;
    }