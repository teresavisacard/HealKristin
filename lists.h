#ifndef LISTS_H
#define LISTS_H

typedef struct Node {
    int city;
    int x, y;
    struct Node *next;
} Node;

typedef struct {
    Node **unions;
    Node **tails;
} Vector;

Vector *create_vector(Clusters *c, Dots **d);

void print_clusters(Clusters *c, Vector *v, FILE *rfile);
void free_cluster_vector(Clusters *c, Vector *v);

#endif