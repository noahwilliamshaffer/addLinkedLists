class Solution {
public:
    
    //function addTwoNumbers takes in two linked lists as parameters and returns a linked list containing the sum of the two linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
    //create a list node called preHead with an initial value of zero
    ListNode preHead(0), *p = &preHead;
        
    //initilize int extra to zero, it will represent the carry over 
    int extra = 0;
        
    //when all of these equal zero we are finished with the while loop 
    while (l1 || l2 || extra) {
        
        //ternary operator essentially saying that if l1 and l2 don't have values then set them equal to zero
        //add their values together + the carry over (either 1 or 0)
        //assign the resulting value to sum 
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        
        //the extra is equal to sum / 10 which will result in either a 1 or a 10
        extra = sum / 10;
        
        //the pointer we created is now calling upon the address of the next node and setting it equal to the sum % 10
        p->next = new ListNode(sum % 10);
        
        //now we set our pointer to the address of the next node
        p = p->next;
        
        //Not sure what this is 
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
    }
};
