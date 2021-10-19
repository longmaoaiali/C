/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root==NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)
        return 1;
    
    int leftDeep = maxDepth(root->left);
    int rightDeep = maxDepth(root->right);
    if(leftDeep > rightDeep){
        return leftDeep+1;
    }else{
        return rightDeep+1;
    }
}