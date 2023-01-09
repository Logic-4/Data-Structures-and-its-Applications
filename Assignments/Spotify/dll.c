#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

list_t *create_list() // return a newly created empty doubly linked list
{
    // DO NOT MODIFY!!!
    list_t *l = (list_t *)malloc(sizeof(list_t));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void insert_front(list_t *list, int data) // TODO: inserts data to the beginning of the linked list
{
    node_t *l = (node_t *)malloc(sizeof(node_t));
    l->data = data;
    if (list->head == NULL && list->tail == NULL)
    {
        list->head = l;
        list->tail = l;
        l->next = NULL;
        l->prev = NULL;
    }
    else
    {
        l->next = list->head;
        l->prev = NULL;
        list->head->prev = l;
        list->head = l;
    }
    list->size = list->size + 1;
}

void insert_back(list_t *list, int data) // TODO: inserts data to the end of the linked list
{
    node_t *l = (node_t *)malloc(sizeof(node_t));
    l->data = data;
    if (list->tail == NULL && list->head == NULL)
    {
        list->head = l;
        list->tail = l;
        l->next = NULL;
        l->prev = NULL;
    }
    else
    {
        l->next = NULL;
        list->tail->next = l;
        l->prev = list->tail;
        list->tail = l;
    }
    list->size = list->size + 1;
}

void insert_after(list_t *list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
    node_t *ptr = list->head;
    while (ptr->data != prev && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->next != NULL)
    {
        node_t *cpt;
        cpt = (node_t *)malloc(sizeof(node_t));
        cpt->data = data;
        cpt->prev = NULL;
        cpt->next = NULL;
        ptr->next->prev = cpt;
        cpt->next = ptr->next;
        cpt->prev = ptr;
        ptr->next = cpt;
    }
    else
    {
        node_t *cpt;
        cpt = (node_t *)malloc(sizeof(node_t));
        cpt->data = data;
        cpt->prev = NULL;
        cpt->next = NULL;
        ptr->next = cpt;
        cpt->prev = ptr;
        list->tail = cpt;
    }
    list->size = list->size + 1;
}

void delete_front(list_t *list) // TODO: delete the start node from the linked list.
{
    if (list->head != NULL)
    {
        node_t *ptr = list->head;
        list->head = list->head->next;
        free(ptr);
        list->head->prev = NULL;
        list->size = list->size - 1;
    }
}

void delete_back(list_t *list) // TODO: delete the end node from the linked list.
{
    if (list->tail != NULL)
    {
        node_t *ptr = list->tail;
        list->tail = list->tail->prev;
        free(ptr);
        list->tail->next = NULL;
        list->size = list->size - 1;
    }
}

void delete_node(list_t *list, int data) // TODO: delete the node with “data” from the linked list.
{
    node_t *ptr = list->head;
    while (ptr->data != data && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->prev == NULL)
    {
        list->head = list->head->next;
        list->head->prev = NULL;
        free(ptr);
        ptr = NULL;
    }
    else if (ptr->next == NULL)
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        ptr = NULL;
    }
    list->size = list->size - 1;
}

node_t *search(list_t *list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
    node_t *ptr = list->head;
    while (ptr->data != data && ptr->next == NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->data == data)
        return ptr;
    else
        return NULL;
}

int is_empty(list_t *list) // return true or 1 if the list is empty; else returns false or 0
{
    // DO NOT MODIFY!!!
    return list->size == 0;
}

int size(list_t *list) // returns the number of nodes in the linked list.
{
    // DO NOT MODIFY!!!
    return list->size;
}

void delete_nodes(node_t *head) // helper
{
    // DO NOT MODIFY!!!
    if (head == NULL)
        return;
    delete_nodes(head->next);
    free(head);
}

void delete_list(list_t *list) // free all the contents of the linked list
{
    // DO NOT MODIFY!!!
    delete_nodes(list->head);
    free(list);
}

void display_list(list_t *list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
    // DO NOT MODIFY!!!
    node_t *it = list->head;
    while (it != NULL)
    {
        printf("%d ", it->data);
        it = it->next;
    }
    printf("\n");
}
