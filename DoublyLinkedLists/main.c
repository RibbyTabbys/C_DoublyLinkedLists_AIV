#include <stdio.h>
#include "DoublyLinkedLists.h"

int main() 
{
    struct list_node *head = NULL;
    struct list_node node1, node2, node3, node4;
    node1.prev = node1.next = NULL;
    node2.prev = node2.next = NULL;
    node3.prev = node3.next = NULL;
    node4.prev = node4.next = NULL;

    list_append(&head, &node1);
    list_append(&head, &node2);
    list_insert_after(&node1, &node3);
    list_insert_before(&head, &node3, &node4);

    struct list_node *current = head;
    while (current != NULL) 
    {
        printf("Node at %p\n", (void *)current);
        current = current->next;
    }

    printf("\nAfter removal of node2:\n");
    list_remove(&head, &node2);
    current = head;
    while (current != NULL) 
    {
        printf("Node at %p\n", (void *)current);
        current = current->next;
    }

    printf("\nAfter shuffling:\n");
    list_shuffle(&head);
    current = head;
    while (current != NULL) 
    {
        printf("Node at %p\n", (void *)current);
        current = current->next;
    }

    return 0;
}
