#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int n_cities;
    int n_links;
    int n_clusters;
    int *id;
    int *sz;
} Graph;

#endif