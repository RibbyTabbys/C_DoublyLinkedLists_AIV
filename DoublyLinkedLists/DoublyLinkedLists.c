#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "DoublyLinkedLists.h"

struct list_node* list_get_tail(struct list_node **head) 
{
    struct list_node *current = *head;
    if (current == NULL) 
    {
        return NULL;
    }
    while (current->next != NULL) 
    {
        current = current->next;
    }
    return current;
}

struct list_node* list_append(struct list_node **head, struct list_node *item) 
{
    struct list_node *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}

void list_remove(struct list_node **head, struct list_node *item) 
{
    if (!item) return;
    
    if (item->prev) {
        item->prev->next = item->next;
    } else {
        *head = item->next;
    }
    
    if (item->next) {
        item->next->prev = item->prev;
    }
    
    item->prev = NULL;
    item->next = NULL;
}

void list_insert_after(struct list_node *existing_item, struct list_node *new_item) 
{
    if (!existing_item || !new_item) return;
    
    new_item->next = existing_item->next;
    new_item->prev = existing_item;
    
    if (existing_item->next) 
    {
        existing_item->next->prev = new_item;
    }
    
    existing_item->next = new_item;
}

void list_insert_before(struct list_node **head, struct list_node *existing_item, struct list_node *new_item) 
{
    if (!existing_item || !new_item) return;
    
    new_item->next = existing_item;
    new_item->prev = existing_item->prev;
    
    if (existing_item->prev) 
    {
        existing_item->prev->next = new_item;
    } 
    else 
    {
        *head = new_item;
    }
    
    existing_item->prev = new_item;
}

void list_shuffle(struct list_node **head) 
{
    if (!head || !*head) return;

    struct list_node *current = *head;
    int count = 0;
    while (current) {
        count++;
        current = current->next;
    }

    if (count < 2) return;

    struct list_node **nodes = malloc(count * sizeof(struct list_node *));
    current = *head;
    for (int i = 0; i < count; i++) 
    {
        nodes[i] = current;
        current = current->next;
    }

    srand((unsigned int)time(NULL));
    for (int i = count - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        struct list_node *temp = nodes[i];
        nodes[i] = nodes[j];
        nodes[j] = temp;
    }

    *head = nodes[0];
    nodes[0]->prev = NULL;
    for (int i = 1; i < count; i++) 
    {
        nodes[i]->prev = nodes[i - 1];
        nodes[i - 1]->next = nodes[i];
    }
    nodes[count - 1]->next = NULL;

    free(nodes);
}