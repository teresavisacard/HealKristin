/**************************************************************
 * @file connectivity.h
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-24
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

void make_set(Dots **d, int a);
void compressed_weighted_quick_union(Clusters *c, Dots **d, int a, int b);
int find_root(Dots **d, int a);

#endif