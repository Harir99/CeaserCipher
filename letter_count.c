#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int letter_count(char* string) {
    char c;
    int i = 0;
    int numletter = 0;
    while (string[i] != '\0'){
        if ((string[i] >= 'a' && string[i] <= 'z') | (string[i] >='A' && string[i] <= 'Z')){
            numletter++;
        }
        i++;
    }
    return numletter;
}
