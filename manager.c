/**************************************************************
 * @file manager.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * 
 * @date 2026-11-18
 **************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"
#include "load.h"
#include "manager.h"
#include "tasks.h"

/**************************************************************
 * @brief Validates the command line arguments.
 * 
 * @param argc Argument Counter
 * @param argv Argument Vector
 * @return int: 0, if unsuccessful;
 *              1, if successful.
 **************************************************************/
int validate_arguments(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <quests> <map> <results>\n", argv[0]);
        return 0;
    }

    /**************************************************************
     * @brief Check File extentions
     **************************************************************/
    if(!strstr(argv[1], ".quests")) {
        return 0;
    }
    if(!strstr(argv[2], ".map")) {
        return 0;
    }
    if(!strstr(argv[3], ".position")) {
        return 0;
    }

    return 1;
}

/**************************************************************
 * @brief 
 * 
 * @param qfilename 
 * @return char* 
 **************************************************************/
FILE *make_rfile(char *qfilename) {
    size_t len = strlen(qfilename);

    char *rfilename = malloc(len + sizeof ".results");
    if (rfilename == NULL) {
        return NULL;
    }

    memcpy(rfilename, qfilename, len);
    memcpy(rfilename, ".results", sizeof ".results");
    FILE *rfile = fopen(rfilename, "w+");

    free(rfilename);
    return rfile;
}

/**************************************************************
 * @brief 
 * 
 * @param qfile 
 * @return int 
 **************************************************************/
int process_quests(FILE *qfile, FILE *mfile, FILE *pfile, FILE *rfile) {
    const Quest tasks[] = {Task1, Task2, Task3, Task4};

    Clusters *c = initialize_clusters();
    if (!load_clusters(c, mfile)) {
        return 1;
    }
    
    Dots **d = initialize_dots(c);
    if (!load_dots(c, d, mfile)) {
        return 1;
    }

    if(!load_map(c, d, mfile)) {
        return 1;
    }
    if(!load_position(c, d, pfile)) {
        return 1;
    }

    int number, arg;
    while (fscanf(qfile, "Task %d", &number) == 1) {
        if (number != 1 && number != 2) {
            if (fscanf(qfile, "%d", &arg) != 1) {
                break;
            }
        }

        if (!tasks[number](c, d, &arg, rfile)) {
            return 1;
        }
    }

    fclose(qfile);
    return 0;
}