#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
// function to return a string that is the concatenation of all the strings pas
// ssed as arguments of the function itself.
char *cStr(char *first, ...) {
  va_list args; 
  size_t t_length = 0;

  // counting the arguments and its length.
  // while cycle to calculate strlen of each arg passed to the variadic functio
  // n.
  va_start(args, first);
  const char *current = first;

  while (current != NULL) {
    t_length += strlen(current);
    // current argument will move forward to the next argument each cycle.
    current = va_arg(args, const char *);
  }
  // at the end of the cycle we know the sum of the lengths of each string.
  
  // close the variadic function arguments cycle.
  va_end(args);
  
  // preallocate the memory for the prefixed length string.
  // TODO: create a malloc and (eventually) a realloc wrapper. ?
  char *result = malloc(t_length + 1); // + 1 stands for null term.
  if (result == NULL) {
    perror("Failed to allocate memory.\n");
    return NULL;
  }
  // initialize result as an empty string, using NULL term.
  result[0] = '\0';
  
  // restart the cycle for the arguments of variadic function
  va_start(args, first);
  // move the index current back to the first arg.
  current = first;
  // create a variable to manage to move forward in the list of args.
  size_t offset = 0;
  // cycle again while not encounter NULL term.
  while (current != NULL) {
    // writes each arg to the result buffer moving towards using offset
    snprintf(result + offset, t_length + 1 - offset, "%s", current);
    // move the cursor at the end of current element strlen.
    offset += strlen(current);
    // assign the value to next* element.
    current = va_arg(args, const char *); 
  }
  // close the args cycle
  va_end(args);

  return result;
}

char *getCurrentDate() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *s = malloc(64 * sizeof(char));
  strftime(s, 64, "%c", tm);
  return s;
}
