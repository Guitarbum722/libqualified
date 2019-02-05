#include <string.h>

int
length(char *strp, const char *sep, const char *qual)
{
    int i = 0;

    // qual is empty or strp does not start with qual
    if (qual[0] == '\0' || !(strncmp(strp, qual, strlen(qual)) == 0)) {
        char *result = strstr(strp, sep);
        if (result == NULL) {
            return strlen(strp);
        }
        i = result - strp;
    } else {
        char qualAndSep[strlen(qual) + strlen(sep)];
        strcpy(qualAndSep, qual);
        strcat(qualAndSep, sep);
        
        char *result = strstr(strp, qualAndSep);
        if (result == NULL) {
            return strlen(strp);
        }
        i = result - strp;

        return strlen(qual) + i;
    }

    if (i == -1) {
        return strlen(strp);
    }
    return i;
}