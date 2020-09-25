# You are given an integer list, print odd-indexed node values first, and then even-indexed node values.
# Note: Indices start from 1.
# Input
## Input contains N space-separated integers. Read input until you encounter -1.
# Output
## Print the output list values seperated by space

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

struct node *create_node(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node *read_inputs_and_create_list()
{
    struct node *dummy_head, *curr;
    //dummy_head->next is the head of the list
    dummy_head = create_node(0);
    curr = dummy_head;
    int input;
    scanf("%d", &input);
    while (input != -1)
    {
        curr->next = create_node(input);
        curr = curr->next;
        scanf("%d", &input);
    }
    return dummy_head->next;
}

void print_list(node *head)
{
    while (head->next != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d", head->data);
}
struct node *odd_even_list(struct node *head)
{
    struct node nodes[2] = {{0, NULL}, {0, NULL}};
    struct node *lists[2] = {&nodes[0], &nodes[1]};
    for (int flag = 0; head; head = head->next, flag = !flag)
        lists[flag] = lists[flag]->next = head;
    lists[0]->next = nodes[1].next;
    lists[1]->next = NULL;
    return nodes[0].next;
}
int main()
{
    struct node *head = read_inputs_and_create_list(), *ans_head;
    ans_head = odd_even_list(head);
    print_list(ans_head);
