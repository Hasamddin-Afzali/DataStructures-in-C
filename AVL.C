#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
};
typedef struct node AVLTREE;

int max(int x, int y){
	return x>=y?x:y;
}
AVLTREE *new_node(int data){
	AVLTREE *new_node = (AVLTREE*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->height = 0;
	new_node->left = NULL;
	new_node->right = NULL;
}
AVLTREE *leftrotate(AVLTREE *z){
	AVLTREE *temp = z->right;
	z->right = temp->left;
	temp->left = z;
	z->height = max(z->left==NULL?-1:z->left->height, z->right==NULL?-1:z->right->height)+1;
	temp->height = max(temp->left==NULL?-1:temp->left->height,temp->right==NULL?-1:temp->right->height)+1;
	return temp;
}
AVLTREE *rightrotate(AVLTREE *z){
	AVLTREE *temp = z->left;
	z->left = temp->right;
	temp->right = z;
	z->height = max(z->left==NULL?-1:z->left->height, z->right==NULL?-1:z->right->height)+1;
	temp->height = max(temp->left==NULL?-1:temp->left->height,temp->right==NULL?-1:temp->right->height)+1;
	return temp;
}

AVLTREE * leftrightrotate(AVLTREE *z){
	z->left = leftrotate(z->left);
	return rightrotate(z);
}
AVLTREE * rightleftrotate(AVLTREE *z){
	z->right = rightrotate(z->left);
	return leftrotate(z);
}
int height(AVLTREE *t){
	return t==NULL ? -1 : t->height;
}
AVLTREE *insert(int x, AVLTREE *tree){
	if(tree != NULL){
		if(x<tree->data){
			tree->left = insert(x,tree->left);
		}else{
			tree->right = insert(x, tree->right);
		}
		tree->height = max(height(tree->left),height(tree->right))+1;
		if(height(tree->left) - height(tree->right) >1&&x<tree->left->data)
			return rightrotate(tree);
		if(height(tree->left) - height(tree->right) >1&&x>tree->left->data)
			return leftrightrotate(tree);
		if(height(tree->left) - height(tree->right) <-1&&x>tree->right->data)
			return leftrotate(tree);
		if(height(tree->left) - height(tree->right) <-1&&x<tree->right->data)
			return rightleftrotate(tree);
	}else{
		tree=new_node(x);
	}
	return tree;
}
void inorder(AVLTREE *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

main(){
	AVLTREE *t = new_node(10);
	t = insert(20,t);
	t = insert(30,t);
	t = insert(5,t);
	printf("%d",t->data);
	//inorder(t);
}











