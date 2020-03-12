#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

char encode (char c, int shift){
    int length;
    int i;
    int count_lower;
    int count_upper;
    int exceed;

    count_upper = (90 - shift);
    count_lower = (122 - shift);
    exceed = (26 - shift);

    if ( shift >= 0 ){
            if(c>= 65 && c<= count_upper ){
                c = c + shift;
            }
            else if((c >= (count_upper+1)) && c <= 90){
            c = c - exceed;
            }

            else if(c >= 97 && c <= count_lower){
                c = c+ shift;
            }
            else if((c >= (count_lower + 1)) && c <= 122 ){
                c = c - exceed;
            }

    }
    else if ( shift < 0){
        // shift = (shift * (- 1));
        for ( i = 0; i < length; i++) {
            if(c >= 97 && c <= 122 ){
                c = c + shift;
            }
            // else if((c >= (count_upper+1)) && c <= 90){
            // c = c + exceed;
            // }
            else if(c > 122){
                c = c + 26;
            }

        } if (c >= 65 && c <= 90){
                c = c + shift;
            }
             if(c > 90 ){
                c = c - 122 + 90 -1;
            }
            else if ( c < 122){
                c =c + 26;
            }


        // if ( shift > 26){
        //     printf("Error - negative number is more than -25\n");
        // }
    }

    return c;
}
