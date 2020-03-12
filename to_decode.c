#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "table.h"

int to_decode(int shift){
    if( shift != 0 ){
        shift = 26 - shift; /* minus 26 from the encode shift to get shift to decode */
    }
    else {
        shift = 0; /* if shsift is zero then dont minus  26  from it*/
    }
    return shift;

}
