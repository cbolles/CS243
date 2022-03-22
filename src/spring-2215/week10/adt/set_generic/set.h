#ifndef _SET_H_
#define _SET_H_

#ifndef _SET_IMPL_

typedef struct {}* Set;

#endif

Set new_set(int (*cmp)(void *, void*));

void set_remove(Set set, void *elem);

void set_insert(Set set, void *elem);

int set_empty(Set set);

int set_contains(Set set, void *elem);

void free_set(Set set);

#endif
