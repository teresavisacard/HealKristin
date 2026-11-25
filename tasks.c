/**************************************************************
 * @file tasks.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-18
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#include <stdio.h>

#include "manager.h"
#include "data.h"

/**************************************************************
 * @brief 
 * 
 * @param number 
 * @return const TaskEntry* 
 **************************************************************/
const TaskEntry *find_task(int number) {
    return &tasks[number];
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param arg 
 * @param rfile 
 * @return int 
 **************************************************************/
int task1(Clusters *c, int *arg, FILE *rfile) {
    (void)arg

    if (fprintf(rfile, "Task1 %d\n\n", c->n_clusters) < 0) {
        return 0;
    }
    return 1;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param arg 
 * @param rfile 
 * @return int 
 **************************************************************/
int task2(Clusters *c, Dots **d int *arg, FILE *rfile) {
    (void)arg;

    if (!start_list(c)) {
        return 1;
    }

    for (city = 1; city <= c->n_cities; city++) {
        if (head[d] == 0) {
            continue;
        }

        fprintf(rfile, "Cluster:");

        for (int m = head[c]; m != 0; m = next[m]) {
            fprintf(rfile, " %d", m);
        }
            
        fprintf(rfile, "\n");
    }

    fprintf(rfile, "\n");
    free_list();
    return r;
}


int task3(Clusters *c, int *arg, FILE *rfile) {
    int city = *arg;

    if (city < 1 || city > c->n_cities) {
        if (fprintf(rfile, "Task3 %d -2\n\n", city) < 0) {
            return 0;
        }
    }

    int r = find_root(c, city);
    int closest_city = -1;
    double min_dist = 0.0;

    for (int i = 1; i <= c->n_cities; i++) {
        if (find_root(c, i) == r) {
            continue;
        }

        double dx = (double)(c->x[city] - c->x[i]);
        double dy = (double)(c->y[city] - c->y[i]);
        double dist = dx * dx + dy * dy;

        if (closest_city == -1 || dist < min_dist) {
            min_dist = dist;
            closest_city = i;
        }
    }

    return 1;
}

/**************************************************************
 * @brief 
 * 
 * @param c 
 * @param arg 
 * @param rfile 
 * @return int 
 **************************************************************/
int task4(Clusters *c, int *arg, FILE *rfile) {
    if 
}