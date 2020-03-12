#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

Record* listToFile (Record*list, char* filename){ /* change from linked list to binary file */
    FILE* fp;
        fp = fopen(filename,"a+"); /* open and write to the binary file */

        fseek(fp, 0L, SEEK_END);
        fwrite(list,sizeof(Record),1,fp);
        fclose(fopen(filename,"w"));

    return list;
}
