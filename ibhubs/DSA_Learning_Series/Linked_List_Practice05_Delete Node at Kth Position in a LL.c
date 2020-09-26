#Delete Node at Kth Position in a Linked List
##Given a list of integers of a Linked List and an integer K, write a program to delete the Kth node from the beginning of the list.

#Input
##First line contains space separated integers. Read input until you encounter -1.
Second line contains a single integer K.

#Output
##Print the elements of the Linked List separated by a space after deleting Kth node as mentioned above. Print -1 if no elements remain in the linked list.

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

void delete_node_at_k(){
    int i;
    int k;
    scanf("%d",&k);
    node *prev = head;
    node *temp = head;
    if(head==NULL)
       return;
    if(k>1){
       for(i=1;i<k-1;i++){
        prev=prev->next;
        }
        temp = prev->next;
        prev->next = prev->next->next;
        free(temp);
    }
    else{
       head = temp->next;
       free(temp);
       return;
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
    delete_node_at_k();
    print_list();
    return 0;
}
