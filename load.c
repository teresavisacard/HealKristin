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

#include "graph.h"
#include "load.h"

/**************************************************************
 * @brief 
 * 
 * @param gfilename 
 * @return Graph* 
 **************************************************************/
Clusters *load_map(const char *mfilename) {

    FILE *mfile = fopen(mfilename, "r");
    if (!mfile) {
        return NULL;
    }

    Clusters *c = malloc(sizeof *c);
    if (!c) {
        fclose(mfile);
        return NULL;
    }

    if (fscanf(mfile, "%d %d", &c->n_cities, &c->n_links) != 2) {
        free(c);
        fclose(mfile);
        return NULL;
    }

    c->id = malloc((c->n_cities + 1) * sizeof *c->id);
    c->sz = malloc((c->n_cities + 1) * sizeof *c->sz);
    
    c->x = NULL;
    c->y = NULL;

    if (!c->id || !c->sz) {
        free_clusters(c);
        fclose(mfile);
        return NULL;
    }

    c->n_clusters = c->n_cities;
    compressed_weighted_quick_union(c, mfile);

    fclose(mfile);
    return c;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param pfilename 
 * @return int 
 **************************************************************/
int load_position(Clusters *c, const char *pfilename) {

    FILE *pfile = fopen(pfilename, "r");
    if (!pfile) {
        return 1;
    }

    int max_x, max_y;

    if (fscanf(pfile, "%d %d", &max_x, &max_y) != 2) {
        fclose(pfile);
        return 1;
    }

    c->x = calloc((size_t)c->n_cities + 1, sizeof *c->x);
    c->y = calloc((size_t)c->n_cities + 1, sizeof *c->y);

    if (!c->x || !c->y) {
        fclose(pfile);
        return 1;
    }

    int city, count = 0;
    while (fscanf(pfile, "%d %d %d", &city, &c->x[city], &c->y[city]) == 3) {
        
        if (city > c->n_cities || cx > max_x || cy > max_y) {
            fclose(mfile);
            return 1;
        }

        count++;
    }

    fclose(pfile);

    if (count != c->n_cities) {
        return 0;
    }

    return 1;
}
