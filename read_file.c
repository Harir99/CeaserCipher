#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

char* read_file ( char* file){
    FILE *fp;

    fp = fopen(file,"r");
    if ( fp == NULL){
        printf("file not found\n" );
        return NULL;
    }
    char* string = malloc ( sizeof(char)* file_size(fp));
    fread(string,1,file_size(fp),fp);
    fclose(fp);
    return string;
}
