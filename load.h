#ifndef LOAD_H
#define LOAD_H

Clusters *initialize_clusters();
Dots *initialize_dots(Clusters *c);

int *load_clusters(FILE *mfile);
int *load_dots(FILE *mfile, Clusters *c, Dots **d);

Graph *load_positions(const char *gfilename);

#endif