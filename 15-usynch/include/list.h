#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#ifndef container_of
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - (size_t)(&((type *)0)->member)));
#endif

typedef struct list_entry {
    struct list_entry *flink;
    struct list_entry *blink;
}LIST_ENTRY, *PLIST_ENTRY;

__attribute__((always_inline))
inline void initializeListHead(PLIST_ENTRY listHead) {
    listHead->flink = listHead->blink = listHead;
}

__attribute__((always_inline))
inline bool isListEmpty(LIST_ENTRY * listHead) {
    return (bool)(listHead->flink == listHead);
}

