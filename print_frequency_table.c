#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"


void print_frequency_table (int* counter){
    int i;
    for(i=0;i<26;i++){
        printf("%c => %d\n",i+65,counter[i] );
    }
}
