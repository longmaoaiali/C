/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    int i=0;
    struct ListNode *delnode = head;
    int length=0;
    struct ListNode *p=head;
    while(p){
        length++;
        p=p->next;
    }

    int delIndex = length-n;
    //删除头结点
    if(delIndex==0)
        return head->next;
    //p是末尾

    for(i=0;i<delIndex-1;i++){
        delnode = delnode->next;
    }

    delnode->next = delnode->next->next;

    return head;
}