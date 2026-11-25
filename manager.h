/**************************************************************
 * @file manager.h
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * @date 2026-11-23
 * 
 * @copyright Copyright (c) 2026
 * 
 **************************************************************/

#ifndef MANAGER_H
#define MANAGER_H

int validate_arguments(int argc, char *argv[]);
FILE *make_rfile(char *qfilename);
int process_quests(FILE *qfile, FILE *mfile, FILE *pfile, FILE *rfile);

#endif