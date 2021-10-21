/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Definition for singly-linked TreeNode list.
struct ListTreeNode {
    struct TreeNode *_node;
    struct ListTreeNode *next;
};

struct ListTreeNode *initiateListNode(struct TreeNode *tn) {
    struct ListTreeNode *tmp = malloc(sizeof(struct ListTreeNode));
    tmp->_node = tn;
    tmp->next = NULL;
    return tmp;
}

struct ListQueue {
    struct ListTreeNode *_front;
    struct ListTreeNode *_rear;
};

struct ListQueue *initiateQueue() {
    struct ListQueue *tmp = malloc(sizeof(struct ListQueue));
    tmp->_front = NULL;
    tmp->_rear = NULL;
    return tmp;
}

bool isEmptyQueue(struct ListQueue *q) {
    if (q->_front == NULL) return true;
    return false;
}

int countQueue(struct ListQueue *q) {
    int count = 0;
    for (struct ListTreeNode *tmp = q->_front; tmp != NULL; tmp = tmp->next) count++;
    return count;
}

struct ListTreeNode *pop(struct ListQueue *q) {
    if (isEmptyQueue(q)) return NULL;
    struct ListTreeNode *tmp = q->_front;
    q->_front = q->_front->next;
    if (q->_front == NULL) q->_rear = NULL;
    return tmp;
}

void push(struct ListQueue *q, struct ListTreeNode *ln) {
    if (isEmptyQueue(q)) {
        q->_front = ln;
        q->_rear = ln;
    } else {
        q->_rear->next = ln;
        q->_rear = q->_rear->next;
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    struct ListQueue *queue = initiateQueue();
    struct ListTreeNode *node = initiateListNode(root);

    if (root != NULL) push(queue, node);

    int size = 0;
    int *columnSizes = malloc(sizeof(int) * size);
    int** res = malloc(sizeof(int*) * size);

    int i = 0;
    while (!isEmptyQueue(queue)) {
        size++;
        res = realloc(res, sizeof(int*) * size);
        columnSizes = realloc(columnSizes, sizeof(int) * size);
        columnSizes[i] = countQueue(queue);
        res[i] = malloc(sizeof(int) * (columnSizes[i]));
        int j = 0;

        // Initiate next_queue
        struct ListQueue *next_queue = initiateQueue();

        while (!isEmptyQueue(queue)) {
            struct TreeNode *tmp = pop(queue)->_node;
            res[i][j] = tmp->val;
            if (tmp->left != NULL) {
                node = initiateListNode(tmp->left);
                push(next_queue, node);
            }
            if (tmp->right != NULL) {
                node = initiateListNode(tmp->right);
                push(next_queue, node);
            }
            j++;
        }
        free(queue);
        queue = next_queue;
        i++;
    }
    free(queue);

    *returnColumnSizes = columnSizes;
    *returnSize = size;
    return res;
}
