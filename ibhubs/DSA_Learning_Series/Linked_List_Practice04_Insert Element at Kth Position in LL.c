#Insert Node at Kth Position in a linked list

Given a list of integers of a linked list and an integer K, write a program to insert a node with value '0' at the Kth position from the beginning.
Note: If K = 1, insert node at the beginning of the list. If K = length of list + 1, insert node at the end of the list.

#Input

First line contains space separated integers. Read input until you encounter -1.
Second line contains a single integer K

#Output

Print the elements of linked list separated by a space after inserting a node as mentioned above.

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

void insert_node_at_k(){
    int i;
    int k;
    scanf("%d",&k);
    if(k>1){
            node *prev = head;
            for(i=1;i<k-1;i++){
            prev=prev->next;
            }
            node *new_node = create_node(0);
            new_node->next = prev->next;
            prev->next = new_node;
    }
    else{
            node *new_node = create_node(0);
            new_node->next = head;
            head = new_node;    
    }
    return;
}

void print_list()
{
    node *temp2 = head;
    if(temp2==NULL){
        printf("-1");
        return;
    }
    while(temp2 != NULL)
    {
        printf("%d ",temp2->data);
        temp2 = temp2->next;
    }
    return;
}

int main(){
    connect_nodes();
    insert_node_at_k();
    print_list();
    return 0;
}
