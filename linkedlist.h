#pragma once

typedef struct link link;

typedef struct list list;

list *list_create(void);

void list_delete(list *l);

void list_push_back(list *l, const char *key, int value);

int list_pop_front(list *l);

int list_pop_back(list *l);

int list_size(list *l);

int list_find(list *l, const char *x);