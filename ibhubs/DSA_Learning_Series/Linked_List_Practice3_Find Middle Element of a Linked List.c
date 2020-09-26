#Find Middle Element of a Linked List

#Input
##Given a list of numbers of a linked list, write a program to find the middle element of the linked list.
##Note: Middle element = (length of list / 2).

#Output
##Print a single integer based on the above context.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL,*curr=NULL;

typedef struct node node;
node *create_node(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void connect_nodes(){
    int n;
    node *new_node;
    scanf("%d",&n);
    while(n!=-1){
        if(head == NULL){
            head = create_node(n);
            curr = head;
            scanf("%d",&n);
        }
        else{
            curr->next = create_node(n);
            curr = curr->next;
            scanf("%d",&n);
        }
    }
    
    return;
    
}

int get_middle_element()
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    connect_nodes();
    printf("%d", get_middle_element());

    return 0;
}
