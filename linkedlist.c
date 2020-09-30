#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkedlist.h"

typedef struct link
{
  const char *key;
  int value;
  struct link *next;
} link;

typedef struct list
{
  link *head;
} list;

list *list_create(void)
{
  list *newlist = malloc(sizeof(struct list));
  return newlist;
}

void list_delete(list *l)
{
  link *current_link = l->head;

  while (current_link->next != NULL)
  {
    current_link = current_link->next;
    free(current_link);
  }

  free(l);
}

void list_push_back(list *l, const char *key, int value)
{
  if (l->head == NULL)
  {
    l->head = malloc(sizeof(link));
    l->head->key = key;
    l->head->value = value;
  }
  else
  {
    link *current_link = l->head;

    int comp;
    while (current_link->next)
    {
      comp = strcmp(current_link->key, key);

      if (comp == 0)
      {
        current_link->value = value;
        break;
      }
      current_link = current_link->next;
    }

    if (comp != 0)
    {
      link *new_link = malloc(sizeof(struct link));
      new_link->key = key;
      new_link->value = value;
      current_link->next = new_link;
    }
  }
}

int list_size(list *l)
{
  if (l->head == NULL)
    return 0;

  link *current_link = l->head;
  int size = 0;

  while (current_link->next)
  {
    current_link = current_link->next;
    size++;
  }

  return size;
}

int list_find(list *l, const char *x)
{
  link *current_link = l->head;

  if (current_link == NULL)
    return 0;

  while (current_link->next)
  {
    int cmp = strcmp(current_link->key, x);
    if (cmp == 0)
    {
      return current_link->value;
    }
    current_link = current_link->next;
  }

  return 0;
}

void list_remove(list *l, const char *key)
{
  if (l->head->key == key)
  {
    link *obj = l->head;
    l->head = obj->next;
    free(obj);
  }
  else
  {
    for (link *i = l->head; i != NULL; i = i->next)
    {
      if (i->next && i->next->key == key)
      {
        link *deletedObj = i->next;
        i->next = deletedObj->next;
        free(deletedObj);
      }
    }
  }
}

void list_print(link *l)
{
  if (l)
  {
    printf("key:%s, value:%d\n", l->key, l->value);
    list_print(l->next);
  }
}