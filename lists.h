#ifndef LISTS_H
#define LISTS_H

typedef struct {
    int city;
    struct Node *next;
} Node;

typedef struct {
    Node **unions;
} Vector;

Vector *create_cluster_vector(Clusters *c, Dots **d);

void print_clusters(Clusters *c, Vector *v);
void free_cluster_vector(Clusters *c, Vector *v);

#endif