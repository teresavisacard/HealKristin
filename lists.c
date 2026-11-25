/**************************************************************
 * @file lists.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-25
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "lists.h"

/**************************************************************
 * @brief 
 * 
 * @param city 
 * @return Node* 
 **************************************************************/
Node *create_node(int city) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }

    n->city = city;
    n->next = NULL;
    return n;
}

/**************************************************************
 * @brief 
 * 
 * @param head 
 * @param city 
 * @return int 
 **************************************************************/
int insert_end(Node **head, int city) {
    Node *n = create_node(city);
    if (n == NULL) {
        return 1;
    }

    if (*head == NULL) {
        *head = n;
        return 1;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = n;
    return 0;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param d 
 * @return Vector* 
 **************************************************************/
Vector *create_vector(Clusters *c, Dots **d) {
    Vector *v = malloc(sizeof(Vector));
    if (v == NULL) {
        return NULL;
    }

    v->unions = calloc(c->n_clusters, sizeof(Node *));
    if (v->unions == NULL) {
        free(v);
        return NULL;
    }

    int *position = calloc(c->n_cities + 1, sizeof(int));
    if (position == NULL) {
        free_cluster_vector(c, v);
        return NULL;
    }

    int index = 0;
    for (int i = 1; i <= c->n_cities; i++) {
        if (find_root(d, i) == i) {
            position[i] = index++;
        }
    }

    for (int i = 1; i <= c->n_cities; i++) {
        int r = find_root(d, i);
        int p = position[r];

        if (!insert_end(&v->unions[p], i)) {
            free(position);
            free_cluster_vector(c, v);
            return NULL;
        }
    }

    free(position);
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param v 
 **************************************************************/
void print_clusters(Clusters *c, Vector *v) {
    for (int i = 0; i < c->n_clusters; i++) {
        printf("Cluster:");
        Node *current = v->unions[i];

        while (current != NULL) {
            printf(" %d", current->city);
            current = current->next;
        }

        printf("\n");
    }

    printf("\n");
}

/**************************************************************
 * @brief 
 * 
 * @param v 
 **************************************************************/
void free_cluster_vector(Clusters *c, Vector *v) {
    if (v == NULL) {
        return;
    }

    for (int i = 0; i < c->n_clusters; i++) {
        Node *current = v->unions[i];

        while (current != NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }

    free(v->unions);
    free(v);
}