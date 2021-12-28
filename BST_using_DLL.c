#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL,*curr,*temp;
struct node *create(){
	curr = (struct node *)malloc(sizeof(struct node));
	printf("Enter Element : ");
	scanf("%d",&curr->data);
	curr -> left = NULL;
	curr -> right = NULL;
	if(root == NULL){
		root = curr;
	}
	else{
		temp = root;
		while(temp!=NULL){
			if(curr->data < temp->data && temp->left == NULL){
				temp->left = curr;
				return root;
			}
			else if(curr->data < temp->data && temp->left != NULL){
				temp = temp -> left;
			}
			else if(curr -> data > temp->data && temp->right == NULL){
				temp->right = curr;
				return root;
			}
			else if(curr -> data > temp->data && temp->right != NULL){
				temp = temp -> right;
			}
	   }
	}
}
void preorder(struct node *root){
	if(root!=NULL){
		printf("%d\t",root->data);
		preorder(root -> left);
		preorder(root -> right);
	}
}
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root -> left);
		printf("%d\t",root -> data);
		inorder(root -> right);
	}
}
void postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
int main(){
	int ch;
	while(1){
		printf("\n1 : Create\n2 : Pre-Order Traversal\n3 : In-Order Traversal\n4 : Post-Order Traversal\n5 : Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1 : root = create();
					 break;
			case 2 : preorder(root);
					 break;
			case 3 : inorder(root);
					 break;
			case 4 : postorder(root);
					 break;
			case 5 : exit(0);
		}
	}
}

