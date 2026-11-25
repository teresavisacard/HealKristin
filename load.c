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
    Dots **d = calloc((int)c->n_cities, sizeof *d);
    if (!d) {
        return NULL;
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
    compressed_weighted_quick_union(c, d, mfile);
    fclose(mfile);

    return 0;
}

/**************************************************************
 * @brief 
 * 
 * @param gfilename 
 * @return Graph* 
 **************************************************************/
int load_map(Clusters *c, Dots **d, FILE *mfile) {

    if (fscanf(mfile, "%d %d", &c->n_cities, &c->n_links) != 2) {
        free(c);
        fclose(mfile);
        return 1;
    }

    c->n_clusters = c->n_cities;
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
int load_position(Clusters *c, Dots **d, FILE *pfile) {
    int max_x, max_y;

    if (fscanf(pfile, "%d %d", &max_x, &max_y) != 2) {
        fclose(pfile);
        return 1;
    }

    int city, count = 0;
    while (fscanf(pfile, "%d %d %d", &city, &d[city]->x, &d[city]->y) == 3) {
        count++;
    }

    fclose(pfile);

    if (count != c->n_cities) {
        return 1;
    }

    return 0;
}