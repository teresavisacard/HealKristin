/**************************************************************
 * @file load.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * 
 * @date 2026-11-18
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "connectivity.h"
#include "load.h"


/**************************************************************
 * @brief 
 * 
 * @return Clusters* 
 **************************************************************/
Clusters *initialize_clusters() {
    Clusters *c = malloc(sizeof *c);
    if (!c) {
        return NULL;
    }

    return c;
}

/**************************************************************
 * @brief 
 * 
 * @param mfilename 
 * @return Clusters* 
 **************************************************************/
int load_clusters(Clusters *c, FILE *mfile) {
    if (fscanf(mfile, "%d %d", &c->n_cities, &c->n_links) != 2) {
        free(c);
        return 1;
    }

    c->n_clusters = c->n_cities;
    return 0;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @return Dots* 
 **************************************************************/
Dots **initialize_dots(Clusters *c) {
    Dots **d = calloc(c->n_cities + 1, sizeof *d);

    if (d == NULL) {
        return NULL;
    }

    for (int i = 1; i <= c->n_cities; i++) {
        d[i] = malloc(sizeof *d[i]);
        if (d[i] == NULL) {
            for (int j = 1; j < i; j++) {
                free(d[j]);
            }

            free(d);
            return NULL;
        }

        make_set(d, i);
    }

    return d;
}

/**************************************************************
 * @brief 
 * 
 * @param mfile 
 * @param c 
 * @param d 
 * @return int* 
 **************************************************************/
int load_dots(Clusters *c, Dots **d, FILE *mfile) {
    int a, b;
    while(fscanf(mfile, "%d %d", &a, &b) == 2) {
        compressed_weighted_quick_union(c, d, a, b);
    }
    
    fclose(mfile);
    return 0;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param pfilename 
 * @return int 
 **************************************************************/
int load_position(Clusters *c, Dots **d, FILE *pfile) {
    int max_x, max_y;
    if (fscanf(pfile, "%d %d", &max_x, &max_y) != 2) {
        return 1;
    }

    int city, x, y, count = 0;
    while (fscanf(pfile, "%d %d %d", &city, &x, &y) == 3) {
        if (city < 0 || city > c->n_cities) {
            return 1;
        }

        d[city]->x = x;
        d[city]->y = y;
        count++;
    }

    if (count != c->n_cities) {
        return 1;
    }

    fclose(pfile);
    return 0;
}