#include <string.h>
#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

char *
strqsep(const char *strp, int sep, int qual)
{
    int in_quotes = FALSE;
    char p[strlen(strp)];
    strcpy(p, strp);
    
    for (int i = 0; i < strlen(p); i++) {

        if (p[i] == qual) {
            in_quotes ^= 1;
            printf("in quotes: %c\n", *strp);
            continue;
        }
        printf("%c", p[i]);
        
        // if (strp[i] == sep && (strp[i] -1) == qual) {
        //     break;
        // }
        // if (strp[i] == qual) {
        //     in_quotes = TRUE;
        //     field_count++;
        //     continue;
        // }
        // printf("%c", strp[i]);
    }
    return NULL;
}