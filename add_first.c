#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"


Record *  add_first (Record * list, Record * element ){
    if(list==NULL){ /* if list is empty then the list will be set to the point to address of the element */
        list = element;

        return list;
    }
    list = element; /* then set teh list to point at the address of the element */
    return list;
}
