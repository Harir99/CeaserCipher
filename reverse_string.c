#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

char* reverse_string(char* buff){
    int i;
    char temp;

    /* reverse string - 24*/
    int len = strlen(buff);
    int j = len;
    int number;
    for(i = 0; i<len;i++){
        temp = buff[j];
        buff[j] = buff[i];
        buff[i] = temp;
        j--;


        if(j == (len/2)){  /* when length is equal to half that means we reversed the string as left half is at the rigth half*/
            break;
        }
    }
    return buff;
}
