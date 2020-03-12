#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"


char* numbers_shifting(char* original, int shift){
    int length;
    int i;
    int count_lower;
    int count_upper;
    int exceed;
    length = strlen(original); /* get the length of the contect */
    original[length] = '\0';

    if(shift <0) {
        shift = shift*-1;

    }

    int realshift = shift%26;
    count_upper = (90 - shift);
    count_lower = (122 - shift);
    exceed = (26 - shift);

    if ( shift >= 0 ){
        for ( i = 0; i < length; i++) {
            if(original[i] >= 65 && original[i] <= count_upper ){
                original[i] = original[i] + shift;
            }
            else if((original[i] >= (count_upper+1)) && original[i] <= 90){
            original[i] = original[i] - exceed;
            }

            else if(original[i] >= 97 && original[i] <= count_lower){
                original[i] = original[i] + shift;
            }
            else if((original[i] >= (count_lower + 1)) && original[i] <= 122 ){
                original[i] = original[i] - exceed;
            }
        }
    }
    else {

        shift = (shift * (- 1));
        for ( i = 0; i < length; i++) {
            if(original[i] >= 65 && original[i] <= count_upper ){
                original[i] = original[i] - shift;
            }
            else if((original[i] >= (count_upper+1)) && original[i] <= 90){
            original[i] = original[i] + exceed;
            }

            else if(original[i] >= 97 && original[i] <= count_lower){
                original[i] = original[i] - shift;
            }
            else if((original[i] >= (count_lower + 1)) && original[i] <= 122 ){
                original[i] = original[i] + exceed;
            }
            if ( 65 == original[i]){
                original[i] = 90;
            }

        }
        if ( shift > 26){
            printf("Error - negative number is more than -25\n");
        }
    }
    return original;
}
