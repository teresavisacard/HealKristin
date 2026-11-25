/**************************************************************
 * @file main.c
 * @author Sílvio Oliveira e Teresa Varandas
 * 
 * @brief Program entry point.
 * 
 * @date 2026-11-17
 **************************************************************/

#include <stdio.h>

#include "manager.h"

/**************************************************************
 * @brief Program entry point.
 * 
 * @param argc Argument Counter
 * @param argv Argument Vector
 * @return int: 0, if successful;
 *              1, if unsuccessful.
 **************************************************************/
int main(int argc, char *argv[]) {
    if (!validate_arguments(argc, argv)) {
        return 1;
    }

    char *rfilename = make_rfile(argv[1]);
    if (rfile == NULL) {
        return 1;
    }

    FILE *rfile = fopen(rfilename);
    FILE *mfile = fopen(argv[1]);
    FILE *mfile = fopen(argv[2]);
    FILE *pfile = fopen(argv[3]);

    if(!process_quests(qfile, mfile, pfile, rfile)) {
        return 1;
    }

    fclose(qfile)
    fclose(rfile);
    fclose(mfile);
    fclose(pfile);
    return 0;
}