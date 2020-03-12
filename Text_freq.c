#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int* Text_freq (char* file_contents){
    int k;
    int i = 0;
    int* counter = malloc(26 * sizeof(int));

    for (k = 0; k < 26; k++){     /* set the counter of all 26 letters to 0 */
        counter[k] = 0;
    }
    while ( file_contents[i] != '\0'){  /* counts the number of words for each letter, but stops when it reaches Null pointer */
        int index = 0;
        if (file_contents[i]>= 'a' && file_contents[i] <= 'z') {
            index = file_contents[i] - 'a';
        }
        if (file_contents[i] >= 'A' && file_contents[i] <= 'Z'){
            index = file_contents[i] - 'A';
        }
        counter[index]++;

            i++;
        }

    return counter;
}
