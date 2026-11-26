/**************************************************************
 * @file tasks.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-24
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

 
#include <stdio.h>

#include "data.h"
#include "manager.h"
#include "tasks.h"
#include "lists.h"
/*
int Task1(Clusters *c, Dots **d, int *arg, FILE *rfile) {
    (void)arg;
    (void)d;

    if (fprintf(rfile, "Task1 %d\n\n", c->n_clusters) < 0) {
        return 1;
    }

    return 0;
}
    */

int Task1(Clusters *c, Dots **d, int *arg, FILE *rfile) {
    (void)arg;
    (void)d;

    fprintf(rfile, "Task1 %d\n\n", c->n_clusters);
    return 0;
}

int Task2(Clusters *c, Dots **d, int *arg, FILE *rfile) {
    (void)arg;
    fprintf(rfile, "Task2 %d", c->n_clusters);
    Vector *v = create_vector(c, d);
    print_clusters(c, v, rfile);
    return 0;
}

int Task3(Clusters *c, Dots **d, int *arg, FILE *rfile)
{

    return 0;
}

int Task4(Clusters *c, Dots **d, int *arg, FILE *rfile)
{
    // Quest 4 implementation
    return 0;
}