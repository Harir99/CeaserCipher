#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#define IN 1  /*inside the word */
#define OUT 0  /* outside the word */
int main(int argc, char** argv) {
    FILE *f1;
    char* original;
    char* new_original;
    char* input;
    int* counter;

    if ( argc == 3 ) {
        input = argv[2];
        if ( argv[1][1] == 'F'){
            input = argv[2];
            if ( (f1 = fopen(input, "r")) != NULL ) {
                original = malloc(sizeof(char)*file_size(f1)+1);
                new_original = malloc(sizeof(char)*file_size(f1)+1);
                fread(original,1,file_size(f1),f1);
                chop(original);
                replace_punc(original); /* delete punctuation */
                remove_spaces(original,new_original);
                letter_count(new_original); /* count how may letters in text as a whole */
                chars_count(original); /* count how may characters in text as a whole */
                counter = Frequency_table(new_original);
                print_frequency_table(counter);
                free(original);
                free(counter);
		        free(new_original);
                fclose(f1);
            }
        }
    }
    else {
	printf("Error - please run the program following this format : ./frequency_table -F input_file\n");
    }
    return 0;
}
