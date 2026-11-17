/**************************************************************
 * @file main.c
 * @author Sílvio Oliveira e Teresa Varandas
 * 
 * @brief Program entry point.
 * Its only jobs: check the command line arguments, terminate if errors arise.
 * 
 * @date 2026-11-17
 **************************************************************/

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
    if(!strstr(argv[1], ".quests")) {
        return 0;
    }
    if(!strstr(argv[1], ".quests")) {
        return 0;
    }

    return 1;
}

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

    if(!process_quests(argv[1])) {
        free_graph();
        return 1;
    }

    return 0;
}