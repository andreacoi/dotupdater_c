#define concatStrings(...) cStr(__VA_ARGS__, NULL)

/**
 * @brief variadic function to concatenate n dynamic strings
 * Freeing memory it's up to the caller.
 * @params char *s1, the first string
 *         char *s2, the second string
 * @return char * -> the string resulting of the concatenation process.
*/
char *cStr(char *first, ...);
