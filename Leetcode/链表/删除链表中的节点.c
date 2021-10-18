struct ListNode {
    int value;
    struct ListNode* next;
};

void deleteNode(struct ListNode* node) {
    //把要删除结点的下一个结点的值赋给要删除的结点
    //然后删除下一个结点
    node->val = node->next->val;
    node->next = node->next->next;
}