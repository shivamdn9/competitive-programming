# Given a list of numbers of a linked list, write a program to remove the Nth node from last.

#Input
##First line contains space separated integers. Read input until you encounter -1.
##Second line contains a single integer N.

#Output
##Print the elements of the linked list separated by a space after removing Nth node from last. Print -1 if no elements remain.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;
// head is the first node and tail is the last node

struct Node *get_new_node(int val)
{
    struct Node *node = malloc(sizeof(struct Node *));
    node->data = val;
    node->next = NULL;
    return node;
}

void insert_nodes()
{
    int temp;
    struct Node *new_node;

    while (1)
    {
        scanf("%d", &temp);
        if (temp == -1)
            break;
        new_node = get_new_node(temp);
        if (head == NULL)
        {
            head = new_node;
            tail = head;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return;
}

void remove_nth_node_from_last()
{
    int n, len = 0;
    scanf("%d", &n);

    struct Node *temp = head, *node_to_free = NULL;
    // find length of list
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    len -= n;

    // if nth node is `head`, we move head to next node.
    if (len == 0)
    {
        node_to_free = head;
        head = head->next;
        free(node_to_free);
        return;
    }
    // find `n-1th` node.
    temp = head;
    while (len > 1)
    {
        len--;
        temp = temp->next;
    }

    // disconnect temp->next and free its memory
    node_to_free = temp->next;
    temp->next = temp->next->next;
    free(node_to_free);

    return;
}

void print_list()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("-1");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

int main()
{
    insert_nodes();
    remove_nth_node_from_last();
    print_list();

    return 0;
}
