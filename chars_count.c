#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int chars_count(char* string) {
    char c;
    int i = 0;
    int numchars = 0;
    while (string[i] != '\0'){

        numchars++;
        i++;
    }
    printf("Total Number of characters in text = %d\n",numchars -1);
}
