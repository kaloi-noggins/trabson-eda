#include <stdlib.h>
#include <stdio.h>
#include "hashmap.h"

int main()
{
  // Algumas strings para testarmos...
  const char *vector[] = {
      "lorem",
      "ipsum",
      "dolor",
      "sit",
      "amet"};

  // Calcula quantidade de strings acima...
  const int length = sizeof vector / sizeof *vector;

  // Por exemplo, se tivermos 512 buckets disponíveis...
  const int capacity = 512;

  hashmap *map = hashmap_create(capacity);

  for (size_t i = 0; i < length; i++)
  {
    const char *s = vector[i];
    int index = elf_hash(s) % capacity;
    //printf("%10s: %d\n", s, index);

    hashmap_set(map, s, i);
  }

  return EXIT_SUCCESS;
}
