/**************************************************************
 * @file data.h
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-23
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#ifndef DATA_H
#define DATA_H

typedef struct {
    int n_cities;
    int n_links;
    int n_clusters;
} Clusters;

typedef struct {
    int id;
    int sz;
    int x, y;
} Dots;

#endif