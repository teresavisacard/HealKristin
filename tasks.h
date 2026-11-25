/**************************************************************
 * @file tasks.h
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-25
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#ifndef TASKS_H
#define TASKS_H

typedef int (*Quest)(Clusters *c, Dots **d, int *arg, FILE *rfile);

int Task1(Clusters *c, Dots **d, int *arg, FILE *rfile);
int Task2(Clusters *c, Dots **d, int *arg, FILE *rfile);
int Task3(Clusters *c, Dots **d, int *arg, FILE *rfile);
int Task4(Clusters *c, Dots **d, int *arg, FILE *rfile);

#endif