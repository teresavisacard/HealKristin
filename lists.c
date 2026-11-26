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
#include "connectivity.h"
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
int insert_end(Node **unions, Node **tails, int city) {
    Node *n = create_node(city);
    if (n == NULL) {
        return 0;
    }

    if (*tails == NULL) {
        *unions = n;
    } else {
        (*tails)->next = n;
    }

    *tails = n;
    return 1;
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

    v->tails = calloc(c->n_clusters, sizeof(Node *));
    if (v->tails == NULL) {
        free(position);
        free_cluster_vector(c, v);
        return NULL;
    }

    int next = 1;
    for (int i = 1; i <= c->n_cities; i++) {
        int r = find_root(d, i);
        if (position[r] == 0) {
            position[r] = next++;
        }

        int p = position[r] - 1;
        if (!insert_end(&v->unions[p], &v->tails[p], i)) {
            free(position);
            free_cluster_vector(c, v);
            return NULL;
        }
    }

    free(position);
    return v;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param v 
 **************************************************************/
void print_clusters(Clusters *c, Vector *v, FILE *rfile) {
    fprintf(rfile, "\n");

    for (int i = 0; i < c->n_clusters; i++) {
        fprintf(rfile, "Cluster:");

        for (Node *cur = v->unions[i]; cur != NULL; cur = cur->next) {
            fprintf(rfile, " %d", cur->city);
        }

        fprintf(rfile, "\n");
    }

    fprintf(rfile, "\n");
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