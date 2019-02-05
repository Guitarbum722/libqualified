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

    char *input = "First,Middle,Last";

    for (int i = 0; i < strlen(input); i++) {
        printf("%c\n", input[i]);
    }


    return 0;
}

