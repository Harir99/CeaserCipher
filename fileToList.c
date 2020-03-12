#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

Record * fileToList(char * filename,int recNum){ /* change from binary back to a linked list */

    FILE * fp = fopen(filename,"rb");
    Record * newRec = malloc(sizeof(Record)); /* create a space in memory for each record  */
    fseek(fp,sizeof(Record)*recNum,SEEK_CUR);
    /* read the new records  into memory one bit at a time, excluding the record *next ,*/
    fread(newRec,(sizeof(Record)),1,fp);

    fclose(fp);
    return newRec;
}
