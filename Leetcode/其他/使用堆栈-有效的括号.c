struct Node{
    char c;
    struct Node* next;
};

struct Queue{
    struct Node* top;
    struct Node* bottom;
};

struct Queue* initQueue(){
    struct Queue* queue = ( struct Queue*)malloc(sizeof(struct Queue));
    queue->top = NULL;
    queue->bottom = NULL;
    return queue;
}

struct Node* initNode(char c){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->c = c;
    node->next = NULL;
    return node;
}

void push(struct Queue* queue,char c){
     struct Node* node = initNode(c);
    //队列为空
    if(queue->top == NULL){
        queue->top = node;
        queue->bottom = node;
    } else {
        node->next = queue->top;
        queue->top = node;
    }
}

char pop(struct Queue* queue){
    if(queue->top == NULL)
        return '0';

    struct Node* node = queue->top;
    queue->top = node->next;
    return node->c;

}

int isQueueEmpty(struct Queue* queue){
    if(queue->top == NULL)
        return 1;

    return 0;
}

bool isValid(char * s){
    int len = strlen(s);
    if(len%2)
        return false;
    int i=0;
    struct Queue* queue = initQueue();
    char c;
    for(i=0;i<len;i++){
        switch(s[i]){
            case '{':
                push(queue,'}');
                break;
            case '(':
                push(queue,')');
                break;
            case '[':
                push(queue,']');
                break;
            case ']':
                if(pop(queue) != ']')
                    return false;
                break;
            case ')':
                if(pop(queue) != ')')
                    return false;
                break;
            case '}':
                if(pop(queue) != '}')
                    return false;
                break;
            
        }
    }

    if(isQueueEmpty(queue)==0)
        return false;

    return true;
}