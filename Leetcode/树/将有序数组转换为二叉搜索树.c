/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize==0)
        return NULL;
    
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    //找到中间的索引
    root->val = nums[numsSize/2];

    root->left = sortedArrayToBST(nums,numsSize/2);
    root->right = sortedArrayToBST(nums+numsSize/2+1,numsSize/2-!(numsSize%2));

    return root;
}