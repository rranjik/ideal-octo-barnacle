

// Complete the removeDuplicates function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if(head!=nullptr){ //list was not empty
        if(head->next==nullptr)//only node in the list
            return head;//return the list
        else if(head->next->data!=head->data){//data in the head and the next node are not equal
            head->next = removeDuplicates(head->next);//continue removing from next node
            return head;
        }
        else{
            auto res = removeDuplicates(head->next->next);
            while((res!=nullptr)&&(res->data == head->data)){
                res = removeDuplicates(res->next);
            }
            head->next = res;
            return head;
        }
    }
    else return nullptr; //return null if list was empty

}

