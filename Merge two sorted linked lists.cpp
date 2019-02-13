

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1==nullptr)
        return head2;
    else if(head2==nullptr)
        return head1;
    else{
        if(head1->data>head2->data){
            SinglyLinkedListNode* ans = new SinglyLinkedListNode(head2->data);
            // (head2->data, mergeLists(head1, head2->next));
            //ans->data = head2->data;
            ans->next = mergeLists(head1, head2->next);
            return ans;
        }
        else{
            SinglyLinkedListNode* ans = new SinglyLinkedListNode(head1->data);
            // (head2->data, mergeLists(head1->next, head2));
            //ans->data = head1->data;
            ans->next = mergeLists(head1->next, head2);
            return ans;
        }
    }
}

