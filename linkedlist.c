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
  newlist->head = malloc(sizeof(struct link));
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
  link *current_link = l->head;

  while (current_link->next != NULL)
  {
    if (current_link->next == NULL)
    {
      break;
    }

    current_link = current_link->next;
  }

  link *new_link = malloc(sizeof(struct link));

  new_link->value = value;
  new_link->key = key;

  current_link->next = new_link;
}

int list_pop_back(list *l)
{
  link *current_link = l->head;

  while (current_link->next != NULL)
  {
    if (current_link->next == NULL)
    {
      break;
    }

    current_link = current_link->next;
  }

  return current_link->value;
}

int list_size(list *l)
{
  link *current_link = l->head;
  int size = 0;

  while (current_link->next != NULL)
  {
    current_link = current_link->next;
    size++;
  }

  return size;
}

int list_find(list *l, const char *x)
{
  //printf("%s", x);
  link *current_link = l->head;

  while (current_link->next != NULL)
  {
    //printf("%s", l->head->key);
    if (strcmp(current_link->key, x) == 0)
    {
      return 1;
    }
    current_link = current_link->next;
  }

  return 0;
}