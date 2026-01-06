#define concatStrings(...) cStr(__VA_ARGS__, NULL)

/**
 * @brief variadic function to concatenate n dynamic strings
 * Freeing memory it's up to the caller.
 * @params char *s1, the first string
 *         char *s2, the second string
 * @return char * -> the string resulting of the concatenation process.
*/
char *cStr(char *first, ...);

/**
 * @brief function to get current date
 * @return char * -> a string that contains the date.
*/
char *getCurrentDate();
