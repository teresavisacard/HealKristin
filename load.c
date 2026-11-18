/**************************************************************
 * @file load.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-18
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#include <stdio.h>

#include "graph.h"
#include "load.h"

Graph *load_graph(const char *gfilename) {
    FILE *gfile = fopen(gfilename, "r");

    //! GUARDRAILS ! FILE VALIDATION !
    if (!gfile) {
        return NULL;
    }

    Graph *g = malloc(sizeof *g);

    if (!g) {
        fclose(gfile);
        return NULL;
    }
    if (fscanf(gfile, "%d %d", &g->n_cities, &g->n_links) != 2) {
        free(g);
        fclose(gfile);
        return NULL;
    }

    g->id = malloc((g->n_cities + 1) * sizeof *g->id);
    g->sz = malloc((g->n_cities + 1) * sizeof *g->sz);
    
    g->x = NULL;
    g->y = NULL;

    if (!g->id || !g->sz) {
        free_graph(g);
        fclose(gfile);
        return NULL;
    }

    g->n_clusters = g->n_cities;
    compressed_weighted_quick_union(g, gfile);
    fclose(gfile);
    return g;
}