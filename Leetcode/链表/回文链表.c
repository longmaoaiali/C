/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){
    struct ListNode* prev=NULL;

    while(head){
		struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
	
	return prev;
}

bool isPalindrome(struct ListNode* head){
    //快慢指针查询链表中间，反转链表的后半部分。之后再遍历比较
    struct ListNode* fast=head;
    struct ListNode* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    //链表长度为奇数
    if(fast!=NULL){
        slow = slow->next;
    }

    //反转slow及其后面的链表
    slow = reverse(slow);

    //遍历 slow fast=head
    fast=head;
    while(slow){
        if(slow->val != fast->val)
            return false;
        
        slow = slow->next;
        fast = fast->next;
    }

    return true;

}