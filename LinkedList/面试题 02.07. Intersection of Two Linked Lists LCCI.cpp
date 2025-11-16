/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*longList=headA;
        ListNode*shortList=headB;
        int longLen=0;
        int shortLen=0;
        while(longList!=NULL){
            longList=longList->next;
            longLen++;
        }
        while(shortList!=NULL){
            shortList=shortList->next;
            shortLen++;
        }

        longList=headA;
        shortList=headB;
        if(longLen<shortLen){
            swap(longLen,shortLen);
            swap(longList,shortList);
        }

        int gap=longLen-shortLen;
        while(gap--){
            longList=longList->next;
        }

        while(longList!=NULL){
            if(longList==shortList)return longList;
            longList=longList->next;
            shortList=shortList->next;
        }
        return NULL;
    }
};