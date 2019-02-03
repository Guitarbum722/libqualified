#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *string,*found;

    string = strdup("First,Middle,Last,Phone");
    printf("Original string: '%s'\n",string);

    while((found = strsep(&string,",")) != NULL) {
        printf("%s\n",found);
    }
    free(string);

    return(0);
}