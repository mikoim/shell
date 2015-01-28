#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include "history.h"
#include "linkedList.h"

#define MAXSIZE 80

char command[MAXSIZE];
char *prompt = "$ ";

void run(char* command) {
    char tmp[MAXSIZE];
    size_t i = 0;
    LinkedList *head, *cur;
    char *arg, *file, **args;

    strcpy(tmp, command);

    head = linkedList_init();
    file = strtok(tmp, " ");

    while ((arg = strtok(NULL, " "))) {
        linkedList_add(head, arg, strlen(arg) + 1);
        i++;
    }

    args = calloc(i + 2, sizeof(char*));
    args[0] = file;

    for (cur = head->next, i = 1; cur != NULL; cur = cur->next, i++)
        args[i] = cur->data;

    args[i] = NULL;

    if (fork() == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execv()");
            exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL);
    }

    free(args);
    linkedList_free(head);
}

int builtin(char *command) {
    if (strlen(command) < 1) {
        return 0;

    } else if (strcmp(command, "exit") == 0) {
        return -1;

    } else if (strcmp(command, "history") == 0) {
        history_dump();
        return 0;

    } else {
        run(command);
        history_add(command);
        return 0;
    }
}

int main() {
    history_init();

    printf("%s", prompt);
    while (fgets(command, 80, stdin) != NULL) {
        command[strlen(command) - 1] = '\0';

        if (builtin(command) == -1) break;
        printf("%s", prompt);
    }

    history_close();

    return 0;
}
