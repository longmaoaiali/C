/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL || head->next==NULL)
        return head;
    
    struct ListNode* p1=head;
    struct ListNode* p2=head->next;
    head->next=NULL;
    while(p2){
        struct ListNode* tmp=p2->next;
        
        p2->next = p1;
        p1=p2;
        p2=tmp;
    }

    return p1;
}