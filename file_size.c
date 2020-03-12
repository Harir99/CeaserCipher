#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int file_size( FILE *fp) {
    int sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp); /* find out the poition of file pointer compared to the beginning of the file */
    rewind(fp); /* moves the file indicator to the beginning of the file */
    return(sz);
}
