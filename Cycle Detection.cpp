
// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    if(head==nullptr||head->next==nullptr)
        return false;
    SinglyLinkedListNode* leader;
    SinglyLinkedListNode* follower;

    leader = head->next->next;
    follower = head;
    if(leader==follower)
        return true;
    else{
        while((leader!=nullptr)&&(leader->next!=nullptr)&&(leader!=follower)){
            leader = leader->next->next;
            follower = follower->next;
        }
        if(leader==follower)
            return true;
        else return false;
    }
}

