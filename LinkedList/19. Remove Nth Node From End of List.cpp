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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode*fast=dummyHead;
        ListNode*slow=dummyHead;
        while(fast!=NULL && n--){
            fast=fast->next;
        }
        fast=fast->next;//保证后面slow的下一个元素是要删除的元素，而且Fast和slow之间相隔n个元素
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        ListNode*ret=dummyHead->next;
        delete dummyHead;
        return ret;
    }
};