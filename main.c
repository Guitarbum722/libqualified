#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "qual.h"

int main()
{
    char *string,*found;
    const char *st2 = strdup("wowzers");
    printf("%s\n", st2);

    string = strdup("First,\"Middle, name\",Last,Phone");
    printf("Original string: '%s'\n",string);

    while((found = strsep(&string, ",")) != NULL) {

        
        printf("%s\n", found);
        printf("wow%c\n", *(found-2));
    }
    printf("%d\n", length(NULL, NULL, NULL));
    free(string);

    return 0;
}

