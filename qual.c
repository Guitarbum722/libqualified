#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1;
#define FALSE 0;

/*
 * strqsep works similarly to the standard lib function 'strsep'.
 * It accepts a third parameter, qual, which is a text qualifier.
 * The qualifier is often a double or single quote, and wraps a field
 * in delimited data that MIGHT contain the delimiter character itself.
 * 
 * This allows the caller to get the first char pointer to a field (token) 
 * from the input in an effort to parse fields from delimited data; and also 
 * disregards the delimiter character IF it is within the qualifier.
 * 
 * The input 'strp' WILL be modified.  Similarly to strsep, the delimiter
 * of the input will be lost and replaced with a null terminator '\0'.
 * The char pointer returned will be a pointer to the next token, not including
 * the delimiter.  If NULL was provided as input, or the end of strp was met, 
 * then NULL shall be returned.
 */
char *
strqsep(char **strp, const char sep, const char qual) {
    char *field;  //, *start;
    int in_quotes = FALSE;
    size_t count = 0;

    if (strp == NULL || *strp == NULL || **strp == '\0') {
        return NULL;
    }
    field = *strp;
    do {
        if (**strp == qual) {
            in_quotes ^= 1;
            (*strp)++;
            count++;
            continue;
        }
        if (**strp == sep) {
            if (in_quotes) {
                (*strp)++;
                count++;
                continue;
            }
            *(*strp)++ = '\0';  // replace delimiter to terminate string for the returned field
            break;
        }
        (*strp)++;
        count++;
    } while (**strp != '\0');

    return field;
}
