/**************************************************************
 * @file linkedlist.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-19
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "data.h"

List **insert_list(Lists *l, int city) {
    List *l = NULL;
    l = (List *) malloc(sizeof(List));

    if (head == NULL) {
        return 1;
    }

    l->item = city;
    l->next = NULL;
}

List **insert_node(Lists *l, int city) {
    //Inesrt node into a certain list.
}

void free_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}