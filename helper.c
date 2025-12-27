#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *sumStrings(char *s1, char *s2) {
  size_t ls1 = strlen(s1);
  size_t ls2 = strlen(s2);
  size_t l_final = ls1 + ls2 + 1;
  char *final = malloc(l_final);
  strcpy(final, s1);
  strcat(final, s2);
  return final;
}

