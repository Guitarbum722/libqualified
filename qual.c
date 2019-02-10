#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

char *
strqsep(char **strp, const char sep, const char qual)
{
    char *field, *start;
    int in_quotes = FALSE;
    size_t count = 0;

    if (strp == NULL || *strp == NULL || **strp == '\0') {
        return NULL;
    }
    start = *strp;
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
            (*strp)++;
            break;
        }
        (*strp)++;
        count++;
    } while (**strp != '\0');

    field = (char*) malloc(sizeof(char) * (count + 1)); // make room for NUL terminator
    strncpy(field, start, count);
    field[count] = '\0';

    return field;
}
