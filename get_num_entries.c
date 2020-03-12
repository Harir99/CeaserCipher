#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

int get_num_entries (char* filename){
    FILE *fp;
    fp = fopen(filename,"r");

    return file_size(fp)/(sizeof(Record)); /* to find # of rec we get the size of file divided by size of records */

}
