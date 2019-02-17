

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* head1Cpy = head1;
    SinglyLinkedListNode* head2Cpy = head2;

    while(head1Cpy!=head2Cpy){
        head1Cpy = head1Cpy->next;
        head2Cpy = head2Cpy->next;
        if(head1Cpy==nullptr)  
            head1Cpy = head2;
        if(head2Cpy==nullptr)
            head2Cpy = head1;
    }
    return head2Cpy->data;
        // if(head1==nullptr||head2==nullptr)
    //     return 0;
    //else 
    // if(head1->next==nullptr || head2->next == nullptr){
    //     return 0;
    // }
    // if(!head1||!head2){ //is anything null ?
    //     return -1; //if either of them are null we did not find a merge point
    // }
    // else 
    // if(head1==head2){
    //     if(head1)
    //         return head1->data;
    //     else return -1;
    // }
    // else if(head1 && head2 && head1->next == head2->next){
    //     if(head1->next)
    //         return head1->next->data;
    //     else return -2;
    // }
    // // else if(head1->next && head2->next && head1->next->next == head2->next->next){
    // //     if(head1->next->next)
    // //         return head1->next->next->data;
    // //     else return -3;
    // // }
    // else {
    //     if(head1->next == head2)
    //         return head2->data;
    //     else if(head2->next == head1)
    //         return head1->data;
    //     else 
    //         return findMergeNode(head1->next, head2->next);
    // }

    // auto ptr1 = nullptr;
    // auto ptr2 = nullptr;
    // if(ptr1==ptr2){
    //     cout<<"yes both are equal indeed";
    // }
    // else {
    //     cout<<"nope";
    // }
    // return 0;
}

