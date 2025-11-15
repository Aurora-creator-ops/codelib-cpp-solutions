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
    // //双指针法
    // ListNode* reverseList(ListNode* head) {
    //     ListNode*temp;
    //     ListNode*cur=head;
    //     ListNode*pre=NULL;
    //     while(cur){
    //         temp=cur->next;
    //         cur->next=pre;
    //         pre=cur;
    //         cur=temp;
    //     }
    //     return pre;
    // }

    //递归法
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;

        ListNode*last=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;

        return last;
    }
};