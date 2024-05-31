#ifndef DOUBLY_LINKED_LISTS_H
#define DOUBLY_LINKED_LISTS_H

#include <stddef.h>

struct list_node 
{
    struct list_node *prev;
    struct list_node *next;
};

struct list_node* list_get_tail(struct list_node **head);
struct list_node* list_append(struct list_node **head, struct list_node *item);
void list_remove(struct list_node **head, struct list_node *item);
void list_insert_after(struct list_node *existing_item, struct list_node *new_item);
void list_insert_before(struct list_node **head, struct list_node *existing_item, struct list_node *new_item);
void list_shuffle(struct list_node **head);

#endif //DOUBLY_LINKED_LISTS_H