#pragma once
#include <stdbool.h>

//typedefs

typedef struct hashmap hashmap;

typedef struct bucket bucket;

//funtions

unsigned long elf_hash(const char *);

hashmap *hashmap_create(int capacity);

void hashmap_set(hashmap *map, const char *key, int value);

int hashmap_get(hashmap *map, const char *key);

bool hashmap_has(hashmap *map, const char *key);

void hashmap_remove(hashmap *map, const char *key);

int hashmap_size(hashmap *map);

void hashmap_delete(hashmap *map);