/*
Oscar Flores
CPTR 131
Spring 2015
Lab6
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
	int data;
	struct Tree *left;
	struct Tree *right;
}Tree;



Tree *Insert(Tree *node, int y)
{
	if(node == NULL)
	{
		Tree *x;
		x = (Tree *)malloc(sizeof(Tree));
		x->data = y;
		x->left = x->right = NULL;
		return x;
	}
	if(y > (node->data))			//using > or < gets rid of the problem of having to check if somethings been used already
	{
		node->right = Insert(node->right,y);
	}
	else if(y < (node->data))
	{
		node->left = Insert(node->left, y);
	}
	return node;
}

//start here from here until it says "end here", functions were found at http://www.geeksforgeeks.org/618/
void printInorder(Tree *node)		
{
	if(node == NULL)
	{
		return;
	}
	printInorder(node->left);
	printf("%d, ", node->data);
	printInorder(node->right);
}

void printpreorder(Tree *node)		
{
	if(node == NULL)
	{
		return;
	}
	printf("%d, ", node->data);
	printpreorder(node->left);
	printpreorder(node->right);
}

void printpostorder(Tree *node)		//
{
	if(node == NULL)
	{
		return;
	}
	printpostorder(node->left);
	printpostorder(node->right);
	printf("%d, ", node->data);
}
//end here

void printnumbers(Tree *node)
{
	printInorder(node);
	printf("\n");
	printpreorder(node);
	printf("\n");
	printpostorder(node);
}

void free_memory(Tree *node)
{
	if(node == NULL)
	{
		return;
	}
	
}

int main()
{
	Tree *root = NULL;
	int x;
	
	while(x > 0)			//for some reason this still returns the negative number along with the rest
	{
		printf("enter a number(negative to exit): ");
		scanf("%d", &x);
		
		root = Insert(root, x);
		printnumbers(root);
		printf("\n");
		
	}
	
	return 0;
}


