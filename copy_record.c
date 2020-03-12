#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "table.h"

int main(int argc, char *argv[]) {
    /* variable calling */
    FILE *fp;
    char buff[24];
    char temp;
    double num;
    char string[144];
    int value;
    char buff2[24];
    char string2[144];
    char* file_to_write;
    char* file_companion;

    char* file_to_read = NULL;
    int file_in = 0;
    int file_out = 0;
    int i;
    int r_on = 0;
    int D_on = 0;
    char* file_str  = NULL;
    char* new_file_str = NULL;

    EF[0] = 0.08167;
    EF[1] = 0.01492;
    EF[2] = 0.02782;
    EF[3] = 0.04253;
    EF[4] = 0.12702;
    EF[5] = 0.02228;
    EF[6] = 0.02015;
    EF[7] = 0.06094;
    EF[8] = 0.06966;
    EF[9] = 0.00153;
    EF[10] = 0.00722;
    EF[11] = 0.04025;
    EF[12] = 0.02406;
    EF[13] = 0.06749;
    EF[14] = 0.07707;
    EF[15] = 0.01929;
    EF[16] = 0.00095;
    EF[17] = 0.05987;
    EF[18] = 0.06327;
    EF[19] = 0.09056;
    EF[20] = 0.02758;
    EF[21] = 0.00978;
    EF[22] = 0.02360;
    EF[23] = 0.00150;
    EF[24] = 0.01974;
    EF[25] = 0.00074;
    /**  **  ** **  **/
    for ( i = 1; i < argc; i++){

        if( strcmp(argv[i],"-F") == 0){
            file_to_read = argv[i+1];
            file_in = 1;
            i++;

        }
        else if( strcmp(argv[i],"-O") == 0){
            file_to_write = argv[i+1];
            file_out = 1;
            i++;

        }

        else if( strcmp(argv[i],"-D") == 0){
            file_companion = argv[i+1];
            D_on = 1;
            i++;
        }
        else{
            int len=strlen(argv[i]);
            int j;
            for ( j=1;j<len;j++){
                if(argv[i][j]=='r'){
                    r_on = 1;
                }
                else{
                    printf("Error - the flag you used is not valid\n" );
                    exit(0);
                }

            }
        }
    }
    int shift;
    if(D_on == 1){
            file_str = read_file(file_companion);
            new_file_str = malloc_new_file(file_companion);
            shift = encode_shift(file_str,new_file_str);

    }

    if(D_on == 0){
        shift = 0;

    }
    int number;

    if( file_in == 1){

             number = get_num_entries(file_to_read);

    }
    else if( file_in == 0){
        printf("Error - please include an input file (-F file_name)\n");
    }


    int k;
    int j;
    int l;

    if(r_on == 0){
        for (k = 0; k < number; k++) {
            Record* ptr;
            char* decoded_message;
            char* decoded_message2;

            if ( file_in == 1 ){
                    ptr = fileToList(file_to_read,k); /* read the binary file */


            }


            if(shift != 0){
                decoded_message2 = numbers_shifting(ptr->string,26-shift);
                decoded_message = numbers_shifting(ptr->long_char,26-shift);
                if(file_out == 0 ){ /* print to stdout in text format */
                    printf("\n");
                    printf("%s\n",decoded_message2);
                    for(j = 0; j < 24; j++){
                        printf("%lf, ",ptr->value[j]);
                    }
                    printf("\n");
                    printf("%s\n",decoded_message);
                    for(l = 0; l < 12; l++){
                        printf("%d, ",ptr->num[l]);
                    }
                    printf("\n");
                }
                strcpy(ptr->string, decoded_message2); /* copy decode_message2 on into ptr->string  */
                strcpy(ptr->long_char, decoded_message); /* copy decode_message on int ptr->long_char */


                if(file_out == 1){

                    //output to file in binary format
                    listToFile(ptr, file_to_write);


                }

            }
            if(shift == 0){
                decoded_message2 = numbers_shifting(ptr->string,0);
                decoded_message = numbers_shifting(ptr->long_char,0);
                if(file_out == 0 ){
                    printf("\n");
                    printf("%s\n",decoded_message2);
                    for(j = 0; j < 24; j++){
                        printf("%lf, ",ptr->value[j]);
                    }
                    printf("\n");
                    printf("%s\n",decoded_message);
                    for(l = 0; l < 12; l++){
                        printf("%d, ",ptr->num[l]);
                    }
                    printf("\n");
                }
                strcpy(ptr->string, decoded_message2);
                strcpy(ptr->long_char, decoded_message);

                if(file_out == 1){

                    //output to file
                    listToFile(ptr, file_to_write);


                }

            }
        }
    }

    else if(r_on == 1){
        for (k = number-1; k >= 0; k--) { /* reverse text if -r is used */
            Record* ptr;
            char* decoded_message;
            char* decoded_message2;
            double value;
            int num;

            if(file_in == 1){
            ptr = fileToList(file_to_read,k);


            }

            if(shift != 0){
                decoded_message = numbers_shifting(ptr->long_char,26-shift);
                decoded_message2 = numbers_shifting(ptr->string,26-shift);

                if(file_out == 0 ){
                    printf("\n");
                    printf("%s\n",decoded_message2);
                    for(j = 23; j >=0; j--){
                        printf("%lf, ",ptr->value[j]);
                    }
                    printf("\n");
                    printf("%s\n",decoded_message);
                    for(l = 11; l >= 0; l--){
                        printf("%d, ",ptr->num[l]);
                    }
                    printf("\n");
                }
                strcpy(ptr->long_char, decoded_message);
                strcpy(ptr->string, decoded_message2);
                if(file_out == 1){
                    //output to file
                    listToFile(ptr, file_to_write); /* write to file in binary */


                }

            }
            if(shift == 0){
                decoded_message = numbers_shifting(ptr->long_char,20);
                decoded_message2 = numbers_shifting(ptr->string,0);

                if(file_out == 0 ){
                    printf("\n");
                    printf("%s\n",decoded_message2);
                    for(j = 23; j >=0; j--){
                        printf("%lf, ",ptr->value[j]);
                    }
                    printf("\n");
                    printf("%s\n",decoded_message);
                    for(l = 11; l >= 0; l--){
                        printf("%d, ",ptr->num[l]);
                    }
                    printf("\n");
                }
                strcpy(ptr->long_char, decoded_message);
                strcpy(ptr->string, decoded_message2);
                if(file_out == 1){
                    //output to file
                    listToFile(ptr, file_to_write); /* write to file in binary */
                }

            }
            free(ptr);
        }
    }

    free(file_str);
    free(new_file_str);
    return 0;
}
