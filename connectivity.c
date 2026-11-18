/**************************************************************
 * @file connectivity.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * 
 * @date 2026-11-17 (redone)
 **************************************************************/

#include <stdio.h>
#include "graph.h"

/**************************************************************
 * @brief Make each city its own cluster, setting its size to 1.
 * 
 * @param g 
 * @param v 
 **************************************************************/
void make_set(Graph *g, int a) {
    g->id[a] = a;
    g->sz[a] = 1;
}

/**************************************************************
 * @brief 
 * 
 * @param g 
 * @param a 
 * @return int - root of city
 **************************************************************/
int find_root(Graph *g, int a) {
    int i;
    for (i = a; i != id[i]; i = id[i]);

    return i;
}

/**************************************************************
 * @brief 
 * 
 * @param g 
 * @param a 
 * @param b 
 * @return int 
 **************************************************************/
int weighted_union(Graph *g, int a, int b) {
    if (sz[a] < sz[b]) {
        id[a] = b;
        sz[b] += sz[a];
    } else {
        id[b] = a;
        sz[a] += sz[b];
    }
}

void compress(Graph *g, int a) {
    int i, c, t;

    for (i = a; i != id[i]; i = c) {
        c = id[i];
        id[i] = t;
    }
}

void compressed_weighted_quick_union(Graph *g, FILE *gfile) {

   for (int i = 0; i < n_cities; i++) {
      make_set(g, i);
   }

   while (fscanf(fp, "%d %d", &a, &b) == 2) {
    int ra = find_root(g, a);
    int rb = find_root(g, b);
    
    if (ra == rb) {
        continue;
    }

    weighted_union(g, a, b);

    compress(g, a);
    compress(g, b);
    }
}
