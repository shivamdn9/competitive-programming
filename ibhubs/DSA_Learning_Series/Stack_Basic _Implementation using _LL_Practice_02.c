#Implement Stack using Linked List

#Input
##First line contains an integer Q denoting the number of queries
Second line contains Q queries separated by space

#Output
##Pop and print the element in a new line whenever the query asks to pop an element from the stack. Print -1 if the stack is empty.
There is a new line at the end of the output.

#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
	int data;
	struct StackNode *next;
};

struct StackNode *newNode(int data)
{
	struct StackNode *stackNode = (struct StackNode *)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct StackNode *root)
{
	return !root;
}

void push(struct StackNode **root, int data)
{
	struct StackNode *stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
}

int pop(struct StackNode **root)
{
	if (isEmpty(*root))
		return -1;
	struct StackNode *temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int main()
{
	struct StackNode *root = NULL;
	int queries;
	scanf("%d", &queries);
	for (int i = 0; i < queries; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 1)
		{
			int val;
			scanf("%d", &val);
			push(&root, val);
		}
		else if (x == 2)
		{
			printf("%d\n", pop(&root));
		}
	}
	return 0;
}
