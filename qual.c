#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

char *
strqsep(char *strp, int sep, int qual)
{
    char *field, *start;
    int in_quotes = FALSE;
    size_t count = 0;

    if (strp == NULL) {
        return NULL;
    }
    start = strp;

    do {
        count++;
        // printf("%c", *strp);
        if (*strp == qual) {
            in_quotes ^= 1;
            continue;
        }
        if (*strp == sep) {
            if (in_quotes) {
                continue;
            }
            break;
        }
        

    } while (*++strp != '\0');

    field = (char*) malloc(count + 1);
    field[count] = '\0';
    strncpy(field, start, count);
    printf("strp:: %s\n", strp);
    printf("field:: %s\n", field);
    return field;
}
