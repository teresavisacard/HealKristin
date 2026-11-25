#ifndef MANAGER_H
#define MANAGER_H

typedef struct {
    int number;
    int (*run)(int *arg, FILE *rfile);
} TaskEntry;

const TaskEntry tasks[] = {
    { 1, task1 },
    { 2, task2 },
    { 3, task3 },
    { 4, task4 }
};

int validate_arguments(int argc, char *argv[]);
 *make_rfile(const char *qfilename);
int process_quests(const char *qfile);

#endif