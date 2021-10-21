#include <stdio.h>
#include <stdlib.h>

typedef struct ListStackNode{
    int value;
    struct ListStackNode* next;
}ListStackNode;

typedef struct ListStack{
    struct ListStackNode* top;
    struct ListStackNode* bottom;
}ListStack;

struct ListStackNode* initListStackNode(int value){
    struct ListStackNode* node = (struct ListStackNode*) malloc(sizeof(struct ListStackNode));
    node->value = value;
    node->next = NULL;
};

 struct ListStack* initListStack(){
    struct ListStack* listStack = (struct ListStack*) malloc(sizeof(struct ListStack));
    listStack->top = NULL;
    listStack->bottom = NULL;

    return listStack;
}

int countListStack(struct ListStack* listStack){
    int count=0;
    struct ListStackNode* tmp = listStack->top;
    while(tmp!=NULL){
        count++;
        tmp = tmp->next;
    }

    return count;
}

// 1±íÊ¾empty
int isEmptyListStack(struct ListStack* listStack)
{
    if(listStack->bottom == NULL)
        return 1;

    return 0;
}


void push(struct ListStack* listStack,struct ListStackNode* node){
    if(listStack == NULL || node == NULL)
        return;

    printf("1 push value = %d\n",node->value);

    if(isEmptyListStack(listStack)){
        listStack->bottom = node;
        listStack->top = node;
        printf("2 push value = %d\n",node->value);
    } else {
        //listStack->top->next = node;
        //listStack->top = node;
        node->next = listStack->top;
        listStack->top = node;
        printf("3 push value = %d\n",node->value);
    }
}

struct ListStackNode* pop(struct ListStack* listStack)
{
    if(listStack==NULL || isEmptyListStack(listStack))
        return NULL;

    struct ListStackNode* node = listStack->top;
    //node->next = NULL;
    listStack->top = listStack->top->next;

    return node;
}

int main()
{
    printf("main\n");
    struct ListStackNode* node1 = initListStackNode(1);
    struct ListStackNode* node2 = initListStackNode(2);
    struct ListStackNode* node3 = initListStackNode(3);
    struct ListStackNode* node4 = initListStackNode(4);

    struct ListStack* list = initListStack();

    push(list,node1);
    push(list,node2);
    push(list,node3);
    push(list,node4);
    printf("1 count num = %d\n",countListStack(list));
    printf("pop(list)->value = %d\n",pop(list)->value);
    printf("pop(list)->value = %d\n",pop(list)->value);
    printf("pop(list)->value = %d\n",pop(list)->value);
    printf("pop(list)->value = %d\n",pop(list)->value);

    printf("2 count num = %d\n",countListStack(list));


    return 0;
}
