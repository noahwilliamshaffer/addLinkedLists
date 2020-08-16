
//The trick is, when two lists are not equally long, pad the shorter one with zero values. In this way, you don't have to handle the remaining sublist.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    //We create a List Node with the head and prev being initilized to NULL
    ListNode *head = NULL, *prev = NULL;
    
    //initilize int carry to equal zero 
    int carry = 0;
    
    //while list 1 and equal zero or NULL
    while (l1 || l2) {
        
        //initilize v1 and v2 to either the value of l1 and l2 respectively or 0
        int v1 = l1? l1->val: 0;
        int v2 = l2? l2->val: 0;
        
        //initilize temp to the sum of v1 + v2 + carry
        int tmp = v1 + v2 + carry;
        
        //carry will be tmp( The Sum ) / 10 which will result in 1 or 0
        carry = tmp / 10;
        
        //integer val will be a single digit from tmp( the sum ) / 10
        int val = tmp % 10;
        
        //New listNode initilized to val (The single digit from sum)
        ListNode* cur = new ListNode(val);
        
        //head != 0 then head = curr
        if (!head) head = cur;
        
        //prev does not equal 0
        if (prev) prev->next = cur;
        prev = cur;
        l1 = l1? l1->next: NULL;
        l2 = l2? l2->next: NULL;
    }
    if (carry > 0) {
        ListNode* l = new ListNode(carry);
        prev->next = l;
    }
    return head;
}
