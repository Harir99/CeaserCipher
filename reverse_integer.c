#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

int reverse_integer ( int value){
    int remainder = 0;
    int reverse = 0;
    while ( value != 0){
        remainder = value % 10;
        reverse = reverse * 10 + remainder;
        value /= 10;
    }
    return value;
}
