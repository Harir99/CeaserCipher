#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
void remove_spaces(char string[100], char stringNew[100]) {
    int i, j;
    int len = strlen(string)+1;

    for (i = 0, j=0; i < len; i++, j++) {
        // printf("%c",string[i]);
        if(string[i]  == ' ' || string[i] =='\t' || string[i] == '\n') {
            int num_space = 1;
            while(string[i+num_space] == ' ' ||string[i+num_space] =='\t' || string[i+num_space] == '\n'){
                num_space++;
            }
            // printf("at index %d I found %d white spaces\n",i,num_space );/
            i+=num_space;

        }
        stringNew[j] = string[i];
        // printf(">%s<\n",stringNew );
    }


}
