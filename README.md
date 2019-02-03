# libqualified

It's basically `strsep` from `<string.h>`, but allows for quoted fields.

This is useful if the input's delimiter characters is actually part of the data in one or more of the tokens (eg. a comma delimited field in a CSV such as "Moby, M.D.").

### Sample usage

```c
#include <stdio.h>

#include "qual.h"

int 
main()
{
    char *field, *input, *tofree;

    tofree = input = strdup("Don|K|\"Moby, M.D.\"|don.moby@nothing.com");

    while ((field = strqsep(&input, "|", "\"")) != NULL) {
        printf("%s\n", field);
    }
    free(tofree);
    return 0;
}

```

Output:
```
Don
K
"Moby, M.D."
don.moby@nothing.com
```
