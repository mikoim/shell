#include <stdio.h>
#include <string.h>
#include "linkedList.h"
#include "history.h"

#define MAX_BUF 1024

LinkedList *list_history;

void history_init() {
    FILE *fd_history;
    size_t len;
    char buf[MAX_BUF];

    list_history = linkedList_init();

    if ((fd_history = fopen("history", "r")) == NULL) return;

    while (fgets(buf, sizeof(buf), fd_history)) {
        len = strlen(buf);
        buf[len - 1] = '\0';
        linkedList_add(list_history, buf, len);
    }

    fclose(fd_history);
}

void history_add(char *command) {
    linkedList_add(list_history, command, strlen(command));
}

void history_dump() {
    int i = 0;
    LinkedList *cur;

    for (cur = list_history->next; cur != NULL; cur = cur->next, i++)
        printf("%d\t%s\n", i, (char *) cur->data);
}

void history_close() {
    FILE *fd_history;
    size_t len;
    char buf[MAX_BUF];
    LinkedList *cur;

    if (list_history == NULL || (fd_history = fopen("history", "w+")) == NULL) return;

    for (cur = list_history->next; cur != NULL; cur = cur->next) {
        strcpy(buf, (char *) cur->data);
        len = strlen(buf);
        buf[len] = '\n';
        buf[len + 1] = '\0';

        fwrite(buf, len + 1, 1, fd_history);
    }

    linkedList_free(list_history);

    fclose(fd_history);
}