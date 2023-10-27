#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
};


struct node* root;

struct node* insert(struct node* r, int data);
void inOrder(struct node* r);
void preOrder(struct node* r);
void postOrder(struct node* r);

void main()
{

    int i,n, v,choice;
    root = NULL;
    clrscr();
    do
    {
	printf("\n*** Binary Tree Traversal***");
	printf("\n1. Enter Node in Tree: ");
	printf("\n2.InOrder Traversal");
	printf("\n3.PreOrder Traversal");
	printf("\n4.PostOrder Traversal");
	printf("\n5.End Program");

	printf("\n Enter Your Choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:	printf("Enter Data: ");
			scanf("%d", &v);
			root = insert(root, v);
			break;
		case 2:	printf("Inorder Traversal: ");
			inOrder(root);
			printf("\n");
			break;
		case 3:	printf("Preorder Traversal: ");
			preOrder(root);
			printf("\n");
			break;
		case 4:	printf("Postorder Traversal: ");
			postOrder(root);
			printf("\n");
			break;
		case 5: printf("\n End Program");
			break;
		default:
			printf("\n Please Enter Choice from 1 to 5");

	}
    }while(choice !=5);
   getch();
}

struct node* insert(struct node* r, int data)
{
    if(r==NULL)
    {
	r = (struct node*) malloc(sizeof(struct node));
	r->value = data;
	r->left = NULL;
	r->right = NULL;
    }
    else if(data < r->value){
	r->left = insert(r->left, data);
    }
    else {
	r->right = insert(r->right, data);
    }
    return r;

}

void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        printf("%d ", r->value);
        inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
        printf("%d ", r->value);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->value);

    }
}