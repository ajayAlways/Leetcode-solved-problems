class MyLinkedList {
public:
    struct ListNode{
        int val;
        struct ListNode* next;
    };
    ListNode* head = new ListNode();
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        int i=0;
        ListNode *temp = head;
        while(i!=index && temp!=NULL){
            temp = temp->next;
            i++;
        }
        if(i!=index || temp==NULL) return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* temp =  new ListNode();
        temp->val = val;
        temp->next = head;
        head = temp;
    }
    
    void addAtTail(int val) {
        ListNode *temp = head;
        ListNode* node = new ListNode();
        node->val = val;
        node->next = NULL;
        
        if(head==NULL) head=node;
        else{
            while(temp->next!=NULL) temp = temp->next;
            temp->next = node;
        }
       
    }
    
    void addAtIndex(int index, int val) {
        if(index==0) addAtHead(val);
        else{
            ListNode *temp = head;
            for(int i=1;i<=index-1 && temp!=NULL;i++){
                temp = temp->next;
            }

            if(temp!=NULL){
                ListNode *temp2 = temp->next;
                ListNode* node = new ListNode();
                node->val = val;
                node->next = temp2;
                temp->next = node;
            }
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index==0) head = head->next;
        else{
            ListNode *temp = head;
            for(int i=1;i<=index-1 && temp!=NULL;i++){
                temp = temp->next;
            }

            if(temp!=NULL && temp->next!=NULL){
                ListNode *temp2 = temp->next;
                temp->next = temp2->next;
                delete(temp2);
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