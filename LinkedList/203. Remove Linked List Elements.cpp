class Solution {
public:
    // ListNode* removeElements(ListNode* head, int val) {
    //     //不使用虚拟头节点
    //     //如果是删除头结点
    //     while(head!=NULL && head->val==val){
    //         ListNode*temp=head;
    //         head=head->next;
    //         delete temp;
    //     }
    //     //其他节点
    //     ListNode*curr=head;
    //     while(curr!=NULL &&curr->next!=NULL){
    //         if(curr->next->val==val){
    //             ListNode*temp=curr->next;
    //             curr->next=curr->next->next;
    //             delete temp;
    //         }
    //         else{
    //             curr=curr->next;
    //         }
    //     }
    //     return head;
    // }
    
    //使用虚拟头节点
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode*curr=dummyHead;
        while(curr->next!=NULL){
            if(curr->next->val==val){
                ListNode*temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }else{
                curr=curr->next;
            }
        }
        head=dummyHead->next;
        delete dummyHead;
        return head;
    }
};