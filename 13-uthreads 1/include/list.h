#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#ifndef container_of
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr)-(size_t)(&((type *)0)->member)))

#endif

typedef struct list_entry
{
    struct list_entry *flink;
    struct list_entry *blink;
} LIST_ENTRY, *PLIST_ENTRY;

__attribute__((always_inline))
inline void initializeListHead(PLIST_ENTRY listHead) {
    listHead->flink = listHead->blink = listHead;
}

__attribute__((always_inline))
inline bool isListEmpty(LIST_ENTRY * listHead) {
    return (bool)(listHead->flink == listHead);
}

__attribute__((always_inline))
inline bool removeEntryList(PLIST_ENTRY entry) {
    PLIST_ENTRY blink;
    PLIST_ENTRY flink;

    flink = entry->flink;
    blink = entry->blink;
    blink->flink = flink;
    flink->blink = blink;

    return flink == blink;
}

__attribute__((always_inline))
inline PLIST_ENTRY removeHeadList(PLIST_ENTRY listHead) {
    PLIST_ENTRY flink;
    PLIST_ENTRY entry;

    entry = listHead->flink;
    flink = entry->flink;
    listHead->flink = flink;
    flink->blink = listHead;

    return entry;
}

__attribute__((always_inline))
inline PLIST_ENTRY removeTailList(PLIST_ENTRY listHead) {
    PLIST_ENTRY blink;
    PLIST_ENTRY entry;

    entry = listHead->blink;
    blink = entry->blink;
    listHead->blink = blink;
    blink->flink = listHead;
    return entry;
}

__attribute__((always_inline))
inline void insertTailList(PLIST_ENTRY listHead, PLIST_ENTRY entry) {
    PLIST_ENTRY blink;

    blink = listHead->blink;
    entry->flink = listHead;
    entry->blink = blink;
    blink->flink = entry;
    listHead->blink = entry;
}

_atttribute__((always_inline))
inline void insertHeadList(PLIST_ENTRY listHead, PLIST_ENTRY entry) {
    PLIST_ENTRY flink;
    flink = listHead->flink;
    entry->flink = flink;
    entry->blink = listHead;
    flink->blink = entry;
    listHead->flink = entry;
}

#endif