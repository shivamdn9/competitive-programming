#Implement Stack

#Input

##First line contains an integer N, denoting the size of A
##Second line contains N space separated integers A[i]

#Output
##print the required output separated by spaces. There is a space at the end of the output.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

// Function to create a stack 
struct Stack* createStack(unsigned capacity)
{
       struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
       stack->capacity = capacity;
       stack->top =-1;
       stack->array = (int*)malloc(stack->capacity * sizeof(int));
       return stack;
}

// Function to add an item to stack.
void push(struct Stack* stack, int item)
{
     if (stack->top == stack->capacity-1){
         return;
     }
     stack->array[++stack->top] = item;
}

// Function to remove an item from stack.
int pop(struct Stack* stack)
{
	if(stack->top == -1){
	   return INT_MIN;
	}
	return stack->array[stack->top--];
}

// Main Function
int main()
{
     int N;
     scanf("%d",&N);
     struct Stack *stack = createStack(N);
     for (int i = 0; i < N; i++){
         int item;
         scanf("%d",&item);
         push(stack,item);
     }
     while(N>0){
          printf("%d ",pop(stack));
          N--;
     }
}
          
