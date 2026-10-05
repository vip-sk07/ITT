#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode {
    int val;
    int height;
    int count;      
    int size;       
    long long sum;  
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

typedef struct {
    int m;
    int k;
    int* queue;
    int head;
    int tail;
    int count;
    AVLNode* root;
} MKAverage;

AVLNode* createNode(int val) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->val = val;
    node->height = 1;
    node->count = 1;
    node->size = 1;
    node->sum = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int getHeight(AVLNode* n) { return n ? n->height : 0; }
int getSize(AVLNode* n) { return n ? n->size : 0; }
long long getSum(AVLNode* n) { return n ? n->sum : 0LL; }
int max(int a, int b) { return (a > b) ? a : b; }

int getBalance(AVLNode* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

void update(AVLNode* n) {
    if (!n) return;
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    n->size = n->count + getSize(n->left) + getSize(n->right);
    n->sum = (long long)n->val * n->count + getSum(n->left) + getSum(n->right);
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    update(y);
    update(x);
    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    update(x);
    update(y);
    return y;
}

AVLNode* insertNode(AVLNode* node, int val) {
    if (!node) return createNode(val);
    
    if (val == node->val) {
        node->count++;
    } else if (val < node->val) {
        node->left = insertNode(node->left, val);
    } else {
        node->right = insertNode(node->right, val);
    }
    
    update(node);
    
    int balance = getBalance(node);
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);
    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AVLNode* deleteNode(AVLNode* root, int val) {
    if (!root) return root;
    
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->count > 1) {
            root->count--;
            update(root);
            return root;
        }
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->count = temp->count;
            temp->count = 1; 
            root->right = deleteNode(root->right, temp->val);
        }
    }
    
    if (!root) return root;
    
    update(root);
    
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

long long querySumOfFirstP(AVLNode* root, int p) {
    if (!root || p <= 0) return 0LL;
    
    int leftSize = getSize(root->left);
    if (p <= leftSize) {
        return querySumOfFirstP(root->left, p);
    }
    
    long long leftSum = getSum(root->left);
    if (p <= leftSize + root->count) {
        int take = p - leftSize;
        return leftSum + (long long)root->val * take;
    }
    
    int takeNode = root->count;
    return leftSum + (long long)root->val * takeNode + querySumOfFirstP(root->right, p - leftSize - takeNode);
}

MKAverage* mKAverageCreate(int m, int k) {
    MKAverage* obj = (MKAverage*)malloc(sizeof(MKAverage));
    obj->m = m;
    obj->k = k;
    obj->queue = (int*)malloc(sizeof(int) * (m + 1));
    obj->head = 0;
    obj->tail = 0;
    obj->count = 0;
    obj->root = NULL;
    return obj;
}

void mKAverageAddElement(MKAverage* obj, int num) {
    obj->queue[obj->tail] = num;
    obj->tail = (obj->tail + 1) % (obj->m + 1);
    obj->root = insertNode(obj->root, num);
    obj->count++;
    
    if (obj->count > obj->m) {
        int oldest = obj->queue[obj->head];
        obj->head = (obj->head + 1) % (obj->m + 1);
        obj->root = deleteNode(obj->root, oldest);
        obj->count--;
    }
}

int mKAverageCalculateMKAverage(MKAverage* obj) {
    if (obj->count < obj->m) return -1;
    
    long long totalSumExceptTopK = querySumOfFirstP(obj->root, obj->m - obj->k);
    long long bottomKSum = querySumOfFirstP(obj->root, obj->k);
    
    long long midSum = totalSumExceptTopK - bottomKSum;
    int elementsInMiddle = obj->m - 2 * obj->k;
    
    return midSum / elementsInMiddle;
}

void freeTree(AVLNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void mKAverageFree(MKAverage* obj) {
    if (obj) {
        freeTree(obj->root);
        free(obj->queue);
        free(obj);
    }
}

/**
 * Your MKAverage struct will be instantiated and called as such:
 * MKAverage* obj = mKAverageCreate(m, k);
 * mKAverageAddElement(obj, num);
 
 * int param_2 = mKAverageCalculateMKAverage(obj);
 
 * mKAverageFree(obj);
*/