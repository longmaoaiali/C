/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmetricHelper(struct TreeNode* left,struct TreeNode* right){
    if(left==NULL && right==NULL)
        return true;
    
    if(left==NULL || right==NULL || right->val != left->val){
        return false;
    }

    return isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left);
}

bool isSymmetric(struct TreeNode* root){
    //判断二叉树是否是对称，需要从子节点开始比较，两个子节点的值必须相同，并且左子节点的右子节点（如果有）必须等于右子节点的左子节点，左子节点的左子节点必须等于右子节点的右子节点。
    if(root == NULL)
        return true;
    //判断子节点
    return isSymmetricHelper(root->left,root->right);
}