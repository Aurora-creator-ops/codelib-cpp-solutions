/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode*dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode*cur=dummyHead;
        while(cur->next!=NULL && cur->next->next!=NULL){
            ListNode*temp1=cur->next;
            ListNode*temp2=cur->next->next->next;

            cur->next=cur->next->next;
            cur->next->next=temp1;
            cur->next->next->next=temp2;

            cur=cur->next->next;
        }
        ListNode*ret=dummyHead->next;
        delete dummyHead;
        return ret;
    }
};