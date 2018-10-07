#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "image_file.h"
typedef struct node {
    size_t* list_size;
    image* val;
    struct node * next;
} node;

node* create_empty_list(size_t elements);
int insert_empty_node(node* head,size_t index);//indexes starts from 1. 0 means end of the list
void print_list_info(node* head);
int assign_element(node* head,image* im,size_t index);//indexes starts from 1. 0 means first empty element
int delete_list(node* head);
#endif // LIST_H_INCLUDED
