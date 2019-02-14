

// Complete the getNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* follower;
    SinglyLinkedListNode* leader;
    leader = head;
    follower = head;
    while(positionFromTail!=0){
        leader = leader->next;
        positionFromTail--;
    }
    while(leader->next!=nullptr){
        leader = leader->next;
        follower = follower->next;
    }
    return follower->data;
}

