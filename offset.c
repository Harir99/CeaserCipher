#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int offset (char c){
    int index = 0;
    if (c >= 97 && c <= 122) {
        index = c - 97;
    }
    if (c >= 65 && c <= 90){
        index = c - 65;
    }
    return index;
}
