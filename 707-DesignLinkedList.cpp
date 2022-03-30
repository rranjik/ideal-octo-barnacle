class MyLinkedList {
public:
    struct Node{
        int val;
        shared_ptr<Node> next;
        Node(int _v):val(_v){}
    };
    /** Initialize your data structure here. */
    shared_ptr<Node> head{};
    shared_ptr<Node> tail{};
    int size{};
    MyLinkedList() {
        head = make_shared<Node>(-1);
        tail = make_shared<Node>(-1);
        head->next = tail;
    }
    
    void print(){
        auto h = head->next;
        cout<<size<<": ";
        for(int i = 0; i<size; i++){
            cout<<h->val<<" ";
            h = h->next;
        }
        cout<<endl;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto h = head->next;
        if(index<0||index>=size) return -1;
        for(int i = 0; i<size; i++){
            if(index==i) {
                //print();
                return h->val;
            }
            else h = h->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto nn = make_shared<Node>(val);
        size++;
        auto old = head->next;
        head->next = nn;
        nn->next = old;
        //print();
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto prev = head;
        while(prev->next!=tail){
            prev = prev->next;
        }
        auto nn = make_shared<Node>(val);
        prev->next = nn;
        nn->next = tail;
        size++;
        //print();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==size){
            addAtTail(val);
            return;
        }
        if(index<0) return;
        if(index>size) return;
        auto prev = head;
        for(int i = 0; i<size; i++){
            if(i == index){
                cout<<"inserting at i = "<<i<<endl;
                auto nn = make_shared<Node>(val);
                auto old = prev->next;
                prev->next = nn;
                nn->next = old;
                size++;
                //print();
                return;
            }else{
                prev=prev->next;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=size) return;
        auto prev = head;
        for(int i = 0; i<size; i++){
            if(i == index){
                cout<<"deleting at "<<i<<" prev  = "<<prev->val<<endl;
                auto old = prev->next->next;
                prev->next = old;
                size--;
                //print();
                return;
            }else{
                prev=prev->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
