typedef struct linkedList{
    struct linkedList *next;
    void *data;
} LinkedList;

LinkedList* linkedList_init();
void linkedList_add(LinkedList *head, void* data, size_t size);
void linkedList_free(LinkedList *head);