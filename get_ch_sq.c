#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

double get_chi_sq(int shift, char * file_str,char* new_file_str){
    double result = 0.0;
    double next_result = 0.0;
    double numerator = 0.0;
    double denomenator = 0.0;
    double formula = 0.0;

    remove_spaces(file_str,new_file_str);
    int n = letter_count(new_file_str);
    int * freq_table =  Text_freq(new_file_str);
    int i = 0;
    int j = 0;
    char c;
    for ( i = 0; i < 26; i++){
        c = i + 65;

        /* to go through each letter */
                numerator = (n* EF[offset(c)]) - (freq_table[offset(encode(c,shift))]);
                numerator = numerator * numerator;
                denomenator = ((n*n)*EF[offset(c)]);
                formula = numerator/denomenator;
                result = result + formula;


    }
    return result;
}
