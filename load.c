/**************************************************************
 * @file load.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-18
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

// TODO: SEE ARGUMENT CHECKS!

#include <stdio.h>

#include "data.h"
#include "load.h"

Clusters *initialize_clusters() {
    Clusters *c = malloc(sizeof *c);
    if (!c) {
        return NULL;
    }

    return c;
}

Dots *initialize_dots(Clusters *c) {
    Dot *d = calloc((int)c->n_cities, sizeof *d);
    if (!d) {
        return NULL;
    }

    return d;
}

/**************************************************************
 * @brief 
 * 
 * @param mfilename 
 * @return Clusters* 
 **************************************************************/
int *load_clusters(FILE *mfile) {
    if (fscanf(mfile, "%d %d", &c->n_cities, &c->n_links) != 2) {
        free(c);
        return 1;
    }

    c->n_clusters = c->n_cities;
    return 0;
}

int *load_dots(FILE *mfile, Clusters *c, Dots **d) {
    compressed_weighted_quick_union(c, d, mfile);
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
int load_positions(FILE *pfile, Clusters *c, Dots **d) {

    int max_x, max_y;

    if (fscanf(pfile, "%d %d", &max_x, &max_y) != 2) {
        return 1;
    }

    int city, count = 0;
    while (fscanf(pfile, "%d %d %d", &city, &d[city].x, &&d[city].y) == 3) {
        
        if (city > c->n_cities || cx > max_x || cy > max_y) {
            return 1;
        }
        count++;
    }

    if (count != c->n_cities) {
        return 1;
    }

    return 0;
}
