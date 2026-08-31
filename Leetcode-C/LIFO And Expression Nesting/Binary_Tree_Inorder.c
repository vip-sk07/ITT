/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**

 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    traverse(root->left, arr, index);
    arr[*index] = root->val;
    (*index)++;
    traverse(root->right, arr, index);
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int totalNodes = countNodes(root);
    *returnSize = totalNodes;
    
    int* result = (int*)malloc(totalNodes * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    
    int index = 0;
    traverse(root, result, &index);
    return result;
}
