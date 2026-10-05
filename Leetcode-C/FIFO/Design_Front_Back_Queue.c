#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    Node* mid;
    int size;
} FrontMiddleBackQueue;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue* obj = (FrontMiddleBackQueue*)malloc(sizeof(FrontMiddleBackQueue));
    obj->head = NULL;
    obj->tail = NULL;
    obj->mid = NULL;
    obj->size = 0;
    return obj;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    Node* newNode = createNode(val);
    if (obj->size == 0) {
        obj->head = obj->tail = obj->mid = newNode;
    } else {
        newNode->next = obj->head;
        obj->head->prev = newNode;
        obj->head = newNode;
        if (obj->size % 2 == 1) {
            obj->mid = obj->mid->prev;
        }
    }
    obj->size++;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    Node* newNode = createNode(val);
    if (obj->size == 0) {
        obj->head = obj->tail = obj->mid = newNode;
    } else if (obj->size == 1) {
        newNode->next = obj->head;
        obj->head->prev = newNode;
        obj->head = obj->mid = newNode;
    } else {
        if (obj->size % 2 == 0) {
            Node* currMid = obj->mid;
            Node* nextNode = currMid->next;
            currMid->next = newNode;
            newNode->prev = currMid;
            newNode->next = nextNode;
            if (nextNode) nextNode->prev = newNode;
            obj->mid = newNode;
        } else {
            Node* prevNode = obj->mid->prev;
            newNode->next = obj->mid;
            obj->mid->prev = newNode;
            newNode->prev = prevNode;
            if (prevNode) prevNode->next = newNode;
            else obj->head = newNode;
            obj->mid = newNode;
        }
    }
    obj->size++;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    Node* newNode = createNode(val);
    if (obj->size == 0) {
        obj->head = obj->tail = obj->mid = newNode;
    } else {
        obj->tail->next = newNode;
        newNode->prev = obj->tail;
        obj->tail = newNode;
        if (obj->size % 2 == 0) {
            obj->mid = obj->mid->next;
        }
    }
    obj->size++;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    Node* temp = obj->head;
    int val = temp->val;
    
    if (obj->size == 1) {
        obj->head = obj->tail = obj->mid = NULL;
    } else {
        obj->head = obj->head->next;
        obj->head->prev = NULL;
        if (obj->size % 2 == 0) {
            obj->mid = obj->mid->next;
        }
    }
    free(temp);
    obj->size--;
    return val;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    Node* temp = obj->mid;
    int val = temp->val;
    
    if (obj->size == 1) {
        obj->head = obj->tail = obj->mid = NULL;
    } else {
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;
        if (prevNode) prevNode->next = nextNode;
        else obj->head = nextNode;
        if (nextNode) nextNode->prev = prevNode;
        else obj->tail = prevNode;
        
        if (obj->size % 2 == 0) {
            obj->mid = nextNode;
        } else {
            obj->mid = prevNode;
        }
    }
    free(temp);
    obj->size--;
    return val;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    Node* temp = obj->tail;
    int val = temp->val;
    
    if (obj->size == 1) {
        obj->head = obj->tail = obj->mid = NULL;
    } else {
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
        if (obj->size % 2 == 1) {
            obj->mid = obj->mid->prev;
        }
    }
    free(temp);
    obj->size--;
    return val;
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}
