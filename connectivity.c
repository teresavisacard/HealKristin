/**************************************************************
 * @file connectivity.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * 
 * @date 2026-11-17 (redone)
 **************************************************************/

#include <stdio.h>
#include "data.h"

/**************************************************************
 * @brief Make each city its own cluster, setting its size to 1.
 * 
 * @param c
 * @param v 
 **************************************************************/
void make_set(Dots **d, int a) {
    d->id[a] = a;
    d->sz[a] = 1;
}

/**************************************************************
 * @brief 
 * 
 * @param c
 * @param a 
 * @return int - root of city
 **************************************************************/
int find_root(Dots *d, int a) {
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
int weighted_union(Clusters *c, Dots **d, int a, int b) {
    c->n_cities--;
    
    if (d->sz[a] < d->sz[b]) {
        d->id[a] = b;
        d->sz[b] += d->sz[a];
    } else {
        d->id[b] = a;
        d->sz[a] += d->sz[b];
    }
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param a 
 **************************************************************/
void compress(Dots **d int a, int ra) {
    int i, t, c;

    for (i = a; i != d->id[i]; i = t) {
        t = d->id[i];
        d->id[i] = ra;
    }
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param gfile 
 **************************************************************/
void compressed_weighted_quick_union(Clusters *c, Dots **d, FILE *gfile) {


    for (int i = 0; i < c->n_cities; i++) {
      make_set(d, i);
    }

    while (fscanf(fp, "%d %d", &a, &b) == 2) {
        int ra = find_root(d, a);
        int rb = find_root(d, b);
    
        if (ra == rb) {
            continue;
        }

        weighted_union(c, d, a, b);

        compress(d, a);
        compress(d, b);
    }
}