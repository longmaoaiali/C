//先访问根结点，再遍历左右子树，称为“先序遍历”；
//遍历左子树，之后访问根结点，然后遍历右子树，称为“中序遍历”；
//遍历完左右子树，再访问根结点，称为“后序遍历”

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}

void  preOrderTree(struct TreeNode tree){
	if(tree==NULL)
		return;
	printf("%d",tree->val);
	preOrderTree(tree->left);
	preOrderTree(tree->right);
}

void inOrderTree(struct TreeNode tree){
	if(tree==NULL)
		return;
	
	inOrderTree(tree->left);
	printf("%d",tree->val);
	inOrderTree(tree->right);
}

void postOrderTree(struct TreeNode tree){
	if(tree==NULL)
		return;
	
	postOrderTree(tree->left);
	postOrderTree(tree->right);
	printf("%d",tree->val);
}