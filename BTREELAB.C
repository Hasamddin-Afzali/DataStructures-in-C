#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node BTREE;

int leafcount(BTREE *node){
	if(node == NULL){
		return 0;
		
	}else if(node->left == NULL && node->right == NULL){
		return 1;
	}else{
		return leafcount(node->left) + leafcount(node->right);
	}
}

BTREE *new_node(int data){
	BTREE *node = (BTREE *)malloc(sizeof(BTREE));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
//create a new node
BTREE *insert(BTREE * root, int data){
	if(root != NULL){
		if(data<root->data){
			root->left =  insert(root->left, data);
		}else{
			root->right = insert(root->right, data);
		}
	}else{
		root = new_node(data);
	}
	return root;
}

//sum node data
int sumNode(BTREE *root){
	if(root == NULL){
		return 0;
	}else{
		return (root->data + sumNode(root->left ) + sumNode(root->right));
	}
}

//find node depth
int findDepth(BTREE *root, int data){
	if(root == NULL){
		printf("BTREE is Empty !");
		return 0;
	}
	if(root->data == data){
		return 1;
	}else if(data<root->data){
		return 1+ findDepth(root->left, data);
	}else{
		return 1+ findDepth(root->right, data);
	}
}

//find BSTREE HEIGHT

int treeHeight(BTREE *root){
	if(!root){
		return -1;
	}else{
		int leftHeight = treeHeight(root->left);
		int rightHeight = treeHeight(root->right);
		if(leftHeight > rightHeight){
			return leftHeight +1;
		}else{
			return rightHeight +1; 
		}
	}
}

main(){
	BTREE *mroot = new_node(10);
	mroot = insert(mroot, 8);
	mroot = insert(mroot, 7);
	mroot = insert(mroot, 9);
	mroot = insert(mroot, 12);
	mroot = insert(mroot, 13);
	mroot = insert(mroot, 11);
	mroot = insert(mroot, 6);
	
	
	printf("leaf count on the tree %d \n", leafcount(mroot));
	printf("sum of data in BTREE %d \n", sumNode(mroot));
	printf("find Depth of tree %d \n", findDepth(mroot, 6));
	
	int height = treeHeight(mroot);
	printf("height of the tree %d \n", height);
	
	
}





