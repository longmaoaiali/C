/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;
    
    if(l2 == NULL)
        return l1;

    struct ListNode* p1=l1;
    struct ListNode* p2=l2;
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* pHead=head;
    //l2为新的合并的有序链表
    while(p1!=NULL && p2!=NULL){
        if(p1->val > p2->val){
            head->next=p2;
            //head = head->next;
            p2 = p2->next;
        } else {
            head->next = p1;
            //head = head->next;
            p1=p1->next;
        }
        head = head->next;
    }

    if(p1 == NULL){
        //把p2链入进来
        head->next=p2;
    }

    if(p2 == NULL){
        head->next=p1;
    }

    return pHead->next;

}