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
    d[a]->id = a;
    d[a]->sz = 1;
}

/**************************************************************
 * @brief 
 * 
 * @param c
 * @param a 
 * @return int - root of city
 **************************************************************/
int find_root(Dots **d, int a) {
    int i;
    for (i = a; i != d[i]->id; i = d[i]->id);

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
void weighted_union(Clusters *c, Dots **d, int a, int b) {
    c->n_cities--;
    
    if (d[a]->sz < d[b]->sz) {
        d[a]->id = b;
        d[b]->sz += d[a]->sz;
    } else {
        d[b]->id = a;
        d[a]->sz += d[b]->sz;
    }
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param a 
 **************************************************************/
void compress(Dots **d, int a, int ra) {
    int i, j;

    for (i = a; i != d[i]->id; i = j) {
        j = d[i]->id;
        d[i]->id = ra;
    }
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param gfile 
 **************************************************************/
void compressed_weighted_quick_union(Clusters *c, Dots **d, FILE *mfile) {
    int a, b;
    for (int i = 0; i < c->n_cities; i++) {
      make_set(d, i);
    }

    while (fscanf(mfile, "%d %d", &a, &b) == 2) {
        int ra = find_root(d, a);
        int rb = find_root(d, b);
    
        if (ra == rb) {
            continue;
        }

        weighted_union(c, d, a, b);

        compress(d, a, ra);
        compress(d, b, rb);
    }
}