typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    if (stack == NULL) return NULL;
    stack->capacity = 100;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    stack->front = 0;
    stack->rear = 0;
    stack->size = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->size == obj->capacity) {
        int oldCapacity = obj->capacity;
        obj->capacity *= 2;
        int* newData = (int*)malloc(obj->capacity * sizeof(int));
        
        int newRear = 0;
        int currentSize = obj->size;
        for (int i = 0; i < currentSize; i++) {
            int val = obj->data[obj->front];
            obj->front = (obj->front + 1) % oldCapacity;
            
            newData[newRear] = val;
            newRear++;
        }
        
        free(obj->data);
        obj->data = newData;
        obj->front = 0;
        obj->rear = newRear;
    }
    
    obj->data[obj->rear] = x;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;
    
    for (int i = 0; i < obj->size - 1; i++) {
        int temp = obj->data[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;
        obj->data[obj->rear] = temp;
        obj->rear = (obj->rear + 1) % obj->capacity;
    }
}

int myStackPop(MyStack* obj) {
    int val = obj->data[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    if (obj != NULL) {
        free(obj->data);
        free(obj);
    }
}

