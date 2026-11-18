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
 * @param c
 * @param v 
 **************************************************************/
void make_set(Graph *c, int a) {
    g->id[a] = a;
    g->sz[a] = 1;
}

/**************************************************************
 * @brief 
 * 
 * @param c
 * @param a 
 * @return int - root of city
 **************************************************************/
int find_root(Clusters *c, int a) {
    int i;
    for (i = a; i != id[i]; i = id[i]);

    return i;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param a 
 * @param b 
 * @return int 
 **************************************************************/
int weighted_union(Clusters *c, int a, int b) {
    c->n_cities--;
    
    if (sz[a] < sz[b]) {
        id[a] = b;
        sz[b] += sz[a];
    } else {
        id[b] = a;
        sz[a] += sz[b];
    }
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param a 
 **************************************************************/
void compress(Clusters *c, int a, int ra) {
    int i, c;

    for (i = a; i != id[i]; i = c) {
        c = id[i];
        id[i] = ra;
    }
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param gfile 
 **************************************************************/
void compressed_weighted_quick_union(Clusters *c, FILE *gfile) {


    for (int i = 0; i < n_cities; i++) {
      make_set(c, i);
    }

    while (fscanf(fp, "%d %d", &a, &b) == 2) {
        int ra = find_root(c, a);
        int rb = find_root(c, b);
    
        if (ra == rb) {
            continue;
        }

        weighted_union(c, a, b);

        compress(c, a, ra);
        compress(c, b, rb);
    }
}