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
    while (a != d[a]->id) {
        d[a]->id = d[d[a]->id]->id;
        a = d[a]->id;
    }

    return a;
}

int weighted_union(Dots **d, int ra, int rb) {
    if (d[ra]->sz < d[rb]->sz) {
        d[ra]->id = rb;
        d[rb]->sz += d[ra]->sz;
        return rb;
    } else {
        d[rb]->id = ra;
        d[ra]->sz += d[rb]->sz;
        return ra;
    }
}

void compress(Dots **d, int ra, int r) {
    int t;
    for (int i = ra; ra != d[ra]->id; ra = t) {
        t = d[i]->id;
        d[i]->id = r;
    }
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param gfile 
 **************************************************************/
void compressed_weighted_quick_union(Clusters *c, Dots **d, int a, int b) {
    int ra = find_root(d, a);
    int rb = find_root(d, b);
    if (ra == rb) {
        return;
    }

    int r = weighted_union(d, ra, rb);
    compress(d, ra, r);
    compress(d, rb, r);
    c->n_clusters--;
}