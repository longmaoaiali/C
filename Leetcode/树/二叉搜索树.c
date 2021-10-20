/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBSTree(struct TreeNode* root,struct TreeNode* min,struct TreeNode* max)
{
    if(root == NULL)
        return true;
    
    if(min!=NULL && root->val <= min->val)
        return false;
    
    if(max!=NULL && root->val >= max->val)
        return false;

    return (isValidBSTree(root->left,min,root) && isValidBSTree(root->right,root,max));

}

bool isValidBST(struct TreeNode* root){
    //递归
    //root节点的值 要大于左节点，要小于右节点
    //root节点的值 是左子树的最大值，是右子树的最小值
    return isValidBSTree(root,NULL,NULL);
}