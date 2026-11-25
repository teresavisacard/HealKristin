#ifndef DATA_H
#define DATA_H

typedef struct {
    int id;
    int sz;
} Dots;

typedef struct {
    int n_cities;
    int n_links;
    int n_clusters;
    Dots *d;
} Clusters

typedef struct {
    int item;
    struct List * next;
} List;


#endif