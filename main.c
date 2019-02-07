#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "qual.h"



int main()
{
    // char *string, *found;
    // const char *st2 = strdup("wowzers");
    // printf("%s\n", st2);

    // string = strdup("First,Middle,Last,Phone");
    // printf("Original string: '%s'\n",string);

    // while((found = strsep(&string, ",")) != NULL) {
        
    //     printf("%s\n", found);
    // }
    // free(string);

    char *input = "\"First,Middle,Last\"";
    char sep = ',';
    char qual = '"';

    strqsep(input, sep, qual);


    return 0;
}

