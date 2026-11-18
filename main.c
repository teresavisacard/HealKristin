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
    };

    if (!make_rfile(arg[1])) {
        return 1;
    };

    if(!process_quests(argv[1])) {
        return 1;
    }

    return 0;
}