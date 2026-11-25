#include <stdio.h>
#include <stdlib.h>

typedef struct Lists {
    int city;
    struct Lists *next;
} Lists;

Lists **start_lists(Clusters *c, Dots *d) {
    // Allocate array of linked lists
    Lists **head = calloc(c->n_cities, sizeof(Lists *));
    if (head == NULL) {
        return NULL;
    }

    // Keep track of the last node of each list
    Lists **tail = calloc(c->n_cities, sizeof(Lists *));
    if (tail == NULL) {
        free(head);
        return NULL;
    }

    // Populate linked lists with cities
    for (int i = 0; i < c->n_cities; i++) {
        // Find the root of the city
        int root = find_root(d, i);

        Lists *n = malloc(sizeof(Lists));

        if (n == NULL) {
            free(tail);
            free_lists(head, c->n_cities);
            return NULL;
        }

        n->city = i;
        n->next = NULL;

        // If the list is empty
        if (head[root] == NULL) {
            head[root] = n;
        }
        else {
            tail[root]->next = n;
        }

        tail[root] = n;
    }

    free(tail);
    return head;
}

void print_lists(Lists **head, int n_cities) {

    for (int i = 0; i < n_cities; i++) {
        // Skip empty positions
        if (head[i] == NULL) {
            continue;
        }

        Lists *temp = head[i];

        printf("Cluster %d: ", i);

        while (temp != NULL) {
            printf("%d ", temp->city);
            temp = temp->next;
        }

        printf("\n");
    }
}

void free_lists(Lists **head, int n_cities) {
    for (int i = 0; i < n_cities; i++) {
        Lists *temp = head[i];

        while (temp != NULL) {
            Lists *aux = temp;
            temp = temp->next;

            free(aux);
        }
    }

    free(head);
}