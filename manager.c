/**************************************************************
 * @file manager.c
 * @author Sílvio Oliveira e Teresa Varandas
 * @brief 
 * 
 * @date 2026-11-18
 **************************************************************/

#include <string.h>
#include "graph.h"
#include "load.h"

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
char *make_rfile(const char *qfilename) {
    size_t len = strlen(qfilename);

    char *rfilename = malloc(len + sizeof ".results");

    if (rfilename == NULL) {
        return NULL;
    }

    memcpy(qfilename, rfilename, len);
    return rfilename;
}

/**************************************************************
 * @brief 
 * 
 * @param qfile 
 * @return int 
 **************************************************************/
int process_quests(const char *qfile) {
    int number;
    int arg;

    if (!fopen(qfile)) {
        return 0;
    }

    Graph g* = load_map(g);

    if(g == NULL) {
        return 0;
    }

    if (!load_position(g)) {
        return 0;
    }

    while (fscanf(qfile, "Task %d", &number) == 1) {
        arg = 0;

        if (number != 1 && number != 2) {
            if (fscanf(qfile, "%d", &arg) != 1) {
                break;
            }
        }

        const TaskEntry *task = find_task(number);
    }

    fclose(qfile);
    return 1;
}