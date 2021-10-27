/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inOrderTree(struct TreeNode* root,int* array,int* len){

    if(root==NULL)
        return ;
    inOrderTree(root->left,array,len);
    array[(*len)++]=root->val;
    inOrderTree(root->right,array,len);

}

int kthSmallest(struct TreeNode* root, int k){
    if(root==NULL)
        return 0;

    int array[10000];
    int len=0;
    inOrderTree(root,array,&len);

    return array[k-1];
}