ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while(list1 != NULL && list2 != NULL) {
            if(list1 -> val <= list2 -> val) {
                //Create node
                ListNode* node = new ListNode(list1 -> val);
                temp -> next = node;
                list1 = list1 -> next;
            }
            else {
                ListNode* node = new ListNode(list2 -> val);
                temp -> next = node;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }
        while(list1 != NULL) {
            ListNode* node = new ListNode(list1 -> val);
            temp -> next = node;
            list1 = list1 -> next;
            temp = temp -> next;
        }
        while(list2 != NULL) {
            ListNode* node = new ListNode(list2 -> val);
            temp -> next = node;
            list2 = list2 -> next;
            temp = temp -> next;
        }
        //IMP!!!!!!!!!!!!!!!!!!!!!!!
        return ans -> next;
    }