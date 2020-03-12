#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

double reverse_double ( double num){
    double rem = 0;
    double reverse = 0;
    while ( num != 0){
        rem = fmod(num,100);
        reverse = reverse * 100 + rem;
        num /= 100;
    }
    return num;
}
