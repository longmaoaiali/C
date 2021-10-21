//树节点
/*
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
*/

//链表队列的节点
struct ListQueueNode {
    struct TreeNode* data;
    struct ListQueueNode* next;
};

//链表队列 指向头尾 ，尾巴插入 头部取出
struct ListQueue{
    struct ListQueueNode* begin;
    struct ListQueueNode* end;
};

//空队列初始化
struct ListQueue* initListQueue(){
    struct ListQueue* queue = malloc(sizeof(struct ListQueue));
    queue->begin = NULL;
    queue->end = NULL;
    return queue;
}

//队列节点的初始化 树节点的转换
struct ListQueueNode* initListQueueNode(struct TreeNode* treeNode){
    struct ListQueueNode* listQueueNode = malloc(sizeof(struct ListQueueNode));
    listQueueNode->data = treeNode;
    listQueueNode->next = NULL;
    return listQueueNode;
}

//1表示为空 0表示不为空 C语言无bool类型
int isEmptyQueue(struct ListQueue* queue){
    if(queue->begin == NULL)
        return 1;

    return 0;
}

int countQueue(struct ListQueue* queue){
    int count=0;
    struct ListQueueNode* tmp = queue->begin;
    while(tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

//出队列
struct TreeNode* DeQueue(struct ListQueue* queue){
    if(queue->begin == NULL)
        return NULL;

    struct TreeNode* node = queue->begin->data;
    queue->begin = queue->begin->next;
    return node;

}

//入队列
void EnQueue(struct ListQueue* queue,struct TreeNode* node){
    if(node == NULL)
        return;

    struct ListQueueNode* listQueueNode = malloc(sizeof(struct ListQueueNode));
    listQueueNode->data = node;
    listQueueNode->next = NULL;

    if(isEmptyQueue(queue)){
        queue->begin = listQueueNode;
        queue->end = listQueueNode;
    } else {
        queue->end->next = listQueueNode;
        queue->end = listQueueNode;
    }
}

int** levelOrder(struct TreeNode* root,int* returnSize, int** returnColumnSizes) {
    struct ListQueue* queue = initListQueue();
    //struct ListQueueNode* node = initListQueueNode(root);

    if(root!=NULL) EnQueue(queue,root);

    int LayerSize=0;//二叉树层数 即多少行
    //一个数组 保存每一层有多少个元素
    int* columnSize = malloc(sizeof(int)*LayerSize);
    int** res = malloc(sizeof(int*) * LayerSize);
    //*res 指向每一行 层

    int i=0;
    while(!isEmptyQueue(queue)){
        LayerSize++;
        res = realloc(res,sizeof(int*) * LayerSize);
        columnSize = realloc(columnSize,sizeof(int)*LayerSize);
        //保存每一层的元素个数
        columnSize[i]=countQueue(queue);
        res[i] = malloc(sizeof(int) * (columnSize[i]));

        int j=0;
        struct ListQueue* new_queue = initListQueue();
        //处理第i层的节点
        while(!isEmptyQueue(queue)){
            struct TreeNode* tmp =  DeQueue(queue);
            res[i][j]=tmp->val;

            if(tmp->left != NULL){
                EnQueue(new_queue,tmp->left);
            }

            if(tmp->right != NULL){
                EnQueue(new_queue,tmp->right);
            }

            j++;
        }

        free(queue);
        queue = new_queue;
        i++;
    }

    free(queue);

    //*returnColumnSizes 是一个一维数组保存每一层的节点数目
    *returnColumnSizes = columnSize;
    //*returnSize 是int型 保存树的层数
    *returnSize = LayerSize;
    //返回值是二维数组 保存结果
    return res;
}