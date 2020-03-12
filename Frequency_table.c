#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int* Frequency_table (char* array){
    int k;
    int i = 0;
    int* counter = malloc(26 * sizeof(int));

for (k = 0; k < 26; k++){     /* set the counter of all 26 letters to 0 */
    counter[k] = 0;
}
while ( array[i] != '\0'){  /* counts the number of words for each letter, but stops when it reaches Null pointer */
    int index=0;
    if (array[i]>= 97 && array[i] <= 122) {
        index = array[i] - 97;
    }
    if (array[i] >= 65 && array[i] <= 90){
        index = array[i] - 65;
    }

    counter[index]++;

        i++;
    }
    return counter;
}
