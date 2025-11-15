class MyLinkedList {
public:
    struct LinkNode{
        int val;
        LinkNode*next;
        LinkNode(int val):val(val),next(nullptr){}
    };

    LinkNode*dummyHead=new LinkNode(0);
    int size=0;

    MyLinkedList() {

    }
    
    int get(int index) {
        if(index>(size-1) || index<0)return -1;
        LinkNode*curr=dummyHead->next;
        while(index--)curr=curr->next;
        return curr->val;
    }
    
    void addAtHead(int val) {
        LinkNode*temp=new LinkNode(val);
        temp->next=dummyHead->next;
        dummyHead->next=temp;
        size++;
    }
    
    void addAtTail(int val) {
        LinkNode*temp=new LinkNode(val);
        LinkNode*curr=dummyHead;
        while(curr->next!=NULL)curr=curr->next;
        curr->next=temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)return;
        if(index<0)index=0;
        LinkNode*temp=new LinkNode(val);
        LinkNode*curr=dummyHead;
        while(index--)curr=curr->next;
        temp->next=curr->next;
        curr->next=temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>(size-1) || index<0)return;
        LinkNode*curr=dummyHead;
        while(index--)curr=curr->next;
        curr->next=curr->next->next;
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