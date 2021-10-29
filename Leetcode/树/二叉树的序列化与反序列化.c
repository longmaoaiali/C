/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
#define N 20002     // less than 20002 would break some test case.

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    if (!root)  return NULL;

    char *data = (char*)malloc(sizeof(char) * (N * 10));        // N * 10 is necessary, otherwise same case would fail.
    memset(data, 0, sizeof(data));

    int len = 0;
    struct TreeNode *queue[N];
    int front = 0;
    int rear = 0;
    char tmp[10];

    queue[rear++] = root;
    while (front != rear) {
        root = queue[front++];
        if (root == NULL) {
            tmp[0] = '#';
            tmp[1] = '\0';
        } else {
            sprintf(tmp, "%d", root->val);
            queue[rear++] = root->left;
            queue[rear++] = root->right;
        }

        strcat(data, tmp);
        strcat(data, ",");
    }
    data[strlen(data) - 1] = '\0';

    return data;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (!data)  return NULL;

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode *node;

    int len = strlen(data);
    struct TreeNode *queue[N];
    int front = 0;
    int rear = 0;

    char * token = strtok(data, ",");
    root->val = atoi(token);
    queue[rear++] = root;
    while (token != NULL) {
        node = queue[front++];

        token = strtok(NULL, ",");      // left tree
        if (!token) break;              // last call for strtok would return NULL
        if (token[0] != '#') {
            struct TreeNode *node_l = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            node_l->val = atoi(token);
            node->left = node_l;
            queue[rear++] = node_l;
        } else {
            node->left = NULL;
        }

        token = strtok(NULL, ",");      // right tree
        if (token[0] != '#') {
            struct TreeNode *node_r = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            node_r->val = atoi(token);
            node->right = node_r;
            queue[rear++] = node_r;
        } else {
            node->right = NULL;
        }
    }

    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);