//first point next, then do for previous then update prev and next
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {

      }
      ListNode(int x) : val(x), next(nullptr) {

      }
 };

ListNode* reverseList(ListNode* head) {
        //We will use 3 pointers
        
    ListNode *prev = NULL, *curr = head, *nxt;
    while(curr) {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
    }
    head = prev;
        
    return head;
}