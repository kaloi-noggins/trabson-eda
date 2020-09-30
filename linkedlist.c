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

int list_size(list *l)
{
   if(l->head==NULL) return 0;
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
   if(l->head==NULL)return 0;
   link *current_link = l->head;

   while (current_link->next != NULL)
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

void list_remove(list *l, const char* key)
{
  if( l->head->key == key ) {
    link *obj = l->head;
    l->head = obj->next;
    free(obj);
  }
  else {
    for(link *i=l->head;i!=NULL; i=i->next){
      if (i->next && i->next->key==key)  {
         link *deletedObj = i->next;
         i->next = deletedObj -> next;
         free(deletedObj);
      }
    }
  }

}