#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

char* malloc_new_file ( char* file){
    FILE *fp;
    fp = fopen(file,"r");
    char* string = malloc ( sizeof(char)* file_size(fp));
    fclose(fp);
    return string;
}
