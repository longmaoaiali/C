typedef struct MinStack{
    int data;
    int min;
    struct MinStack* next;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->next=NULL;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    MinStack* p=(MinStack*)malloc(sizeof(MinStack));
    p->data= val;
    if(obj->next== NULL)
        p->min = val;
    else
        if(val < obj->next->min)
            p->min = val;
        else    
            p->min = obj->next->min;

    p->next = obj->next;
    obj->next = p;
}

void minStackPop(MinStack* obj) {
    MinStack* p;
    p = obj->next;
    obj->next = p->next;
    free(p);
}

int minStackTop(MinStack* obj) {
    return obj->next->data;
}



int minStackGetMin(MinStack* obj) {
    return obj->next->min;
}

void minStackFree(MinStack* obj) {
    MinStack* p = obj;
    while(obj){
        p = obj->next;
        free(obj);
        obj = p;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/