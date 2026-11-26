/**************************************************************
 * @file load.h
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-23
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#ifndef LOAD_H
#define LOAD_H

Clusters *initialize_clusters();
int load_clusters(Clusters *c, FILE *mfile);

Dots **initialize_dots(Clusters *c);
int load_dots(Clusters *c, Dots **d, FILE *mfile);

int load_position(Clusters *c, Dots **d, FILE *pfile);

#endif