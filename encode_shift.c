#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "table.h"

int encode_shift(char* file_str, char* new_file_str){

    int i;
    int shift = 0;
    double chi_sq = 0.0;
    double lowest_value = DBL_MAX; /* DBL MAX = 1.8 x 10 ^304 */
        for(i = 0; i < 26; i++){ /* loop 26 times where shift keep changing from 0 till 25 */
            chi_sq = get_chi_sq(i,file_str,new_file_str); /* get chi_sq results for all shift values*/
            if(chi_sq < lowest_value){ /* compare it with DBL_MAX and keep getting lower value till we get lowest */
                lowest_value = chi_sq; /* set lowest to the value that you got ess than 2000*/
                shift = i; /* set shift to the shit tat was used to get that value */

            }
        }

        if ( lowest_value >= 0.5){ /* if value of chi_sq is equal to 0.5 or more then set shift = 0 */
            shift = 0;
        }
        return shift;
    }
