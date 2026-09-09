class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>=size)
             return -1;

        if(index == 0)
            return head->val;
    
        if(index == size-1)
            return tail->val;
    
        Node* temp = head;
        for(int i =0; i<index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if(size == 0){
            tail = head = newNode;
            size++;
            return;
        }
        
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(size == 0){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
       
        if(index<0 || index>size) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;

        for(int i = 0; i<index-1 && temp; i++){
            temp = temp->next;
        }
        

       newNode->next = temp->next;
       temp->next = newNode;
       size++;
    }
    
    void deleteAtIndex(int idx) {
        if(idx<0 || idx>=size) return;

        if(idx == 0){
            Node* p = head;
            head = head->next;
            size--;
            delete p;

            if(size == 0) 
                tail = NULL;
    
            return;
        }
        Node* temp = head;

        for(int i = 0; i<idx-1 && temp; i++){
            temp = temp->next;
        }
        if(!temp->next) return;
        Node* p = temp->next;
        temp->next = p->next;
        if(idx == size-1)
            tail = temp;
    
        delete p;
        size--;
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