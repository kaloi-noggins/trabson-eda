#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashmap.h"
#include "linkedlist.h"

/** 
 * Função padronizada para calcular o hash de uma string.
 */
unsigned long elf_hash(const char *s)
{
  unsigned long h = 0;
  for (int i = 0; i < strlen(s); i++)
  {
    h = (h << 4) + s[i];
    unsigned long x = h & 0xF0000000;
    if (x != 0)
    {
      h ^= x >> 24;
      h &= ~x;
    }
  }

  return h;
}

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

struct bucket
{
  list *hashlist;
};

struct hashmap
{
  int capacity;
  list **buckets;
};

hashmap *hashmap_create(int capacity)
{
  if (capacity < 1) return NULL;

  hashmap *map = malloc(sizeof(hashmap));

  map->capacity = capacity;
  map->buckets = malloc(sizeof(list*) * capacity);

  return map;
}

void hashmap_set(hashmap *map, const char *key, int value)
{
  int index = elf_hash(key) % map->capacity;

  printf("index: %03d | key: %s | hash:%ld | value: %d\n", index, key, elf_hash(key), value);

  if (map->buckets[index] == NULL)
  {
    map->buckets[index] = list_create();
  }
  list_push_back(map->buckets[index], key, value);

  printf("size: %d\n", list_size(map->buckets[index]));
}

int hashmap_get(hashmap *map, const char *key)
{
	int index = elf_hash(key) % map->capacity;

	if (map->buckets[index])
	{
		return list_find(map->buckets[index], key); 
	}
	return 0;
	
}

bool hashmap_has(hashmap *map, const char *key)
{
	int index = elf_hash(key) % map->capacity;

	if (map->buckets[index])
	{
		return list_find(map->buckets[index], key)?true:false; 
	}
	return false;

}

void hashmap_remove(hashmap *map, const char *key)
{
	int index = elf_hash(key) % map->capacity;
	if(map->buckets[index]) list_remove(map->buckets[index],key);
}

int hashmap_size(hashmap *map)
{
	
	int count = 0;
	for (int i = 0; i < map->capacity; i++)
	{
		if (map->buckets[i])
		{
			count += list_size(map->buckets[i]);
		}
	}
	return count;

}
void hashmap_delete(hashmap *map)
{
	for (int i = 0; i < map->capacity; i++)
	{
		if (map->buckets[i])
		{
			list_delete(map->buckets[i]);
		}
	}
	free(map->buckets);
	free(map);
}