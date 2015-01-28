#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

LinkedList* linkedList_init() {
    LinkedList *tmp = calloc(1, sizeof(LinkedList));
    return tmp;
}

void linkedList_add(LinkedList *head, void* data, size_t size) {
    while (head->next != NULL)
        head = head->next;

    head->next = calloc(1, sizeof(LinkedList));
    head->next->data = calloc(size, sizeof(char));
    memcpy(head->next->data, data, size);
}

void linkedList_free(LinkedList *head) {
    LinkedList *prev;

    while (head != NULL) {
        prev = head;
        free(head->data);
        head = head->next;
        free(prev);
    }
}