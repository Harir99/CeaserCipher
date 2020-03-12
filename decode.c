#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int main(int argc, char  *argv[]) {
    FILE *f2;

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


    char* file_to_write;
    char* output;
    char string[100];
    char* file_to_read = NULL;
    int file_in = 0;
    int file_out = 0;
    int x_on= 0;
    int s_on = 0;
    int S_on = 0;
    int t_on = 0;
    int n_on = 0;
    int i;

    for ( i = 1; i < argc; i++){
        if( strcmp(argv[i],"-F") == 0){
            file_to_read = argv[i+1]; /* file name comes after the flag so add one to whereever you you find the flag -F */
            file_in = 1;
            i++;

        }
        else if( strcmp(argv[i],"-O") == 0){
            file_to_write = argv[i+1]; /* file name comes after the flag so add one to whereever you you find the flag -O */
            file_out = 1;
            i++;

        }
        else{
            int len=strlen(argv[i]);
            int j;
            for ( j=1;j<len;j++){
                /* the flags could bestuck together so get the length and check for x, s, S , x or n */
                if(argv[i][j]=='x'){
                    x_on = 1;
                }
                else if(argv[i][j]=='s'){
                    s_on = 1;
                }
                else if(argv[i][j]=='S'){
                    S_on = 1;
                }
                else if(argv[i][j]=='t'){
                    t_on = 1;
                }
                else if(argv[i][j] == 'n'){
                    n_on = 1;
                }
                else{
                    printf("Error - the flag you used is not valid\n" );
                    exit(0);
                }
            }
        }
    }
    char* file_str  = NULL;
    char* new_file_str = NULL;
    char* encoded_message;
    char* decoded_message;
    if( file_in == 0 && file_out == 0){
        if( s_on == 0 && S_on == 0 && t_on == 0 && x_on == 0 ){
            printf("Error - no flags provided, therefore no actions to be taken \n");
            exit(0);
        }
    }
    if ( file_in == 1 ) { /* if there is an input file malloc and read file_str and new_file_str using file_size function */
          file_str = read_file(file_to_read);
          new_file_str = malloc_new_file(file_to_read);


}


if (file_in == 0 ){ /* if there is no input file, then get string from stdin */
              int k;
              file_str = malloc(sizeof(char)*1000);
              new_file_str = malloc(sizeof(char)*1000);
              strcpy(file_str,"");
              printf("Enter your input: \n");

              while ( fgets(string,100,stdin) != NULL){  /* keep accepting strings until the user enters a single period '.' */
                  strcat(file_str,string);
              }
          }

    if(file_out == 1){
                if (f2 = fopen(file_to_write, "w") ) { /* if there is an output file then open it to write */
                    char c;
                    int k;
                    int shift = encode_shift(file_str,new_file_str); /* get the shift made by encode_shift func*/
                    chop(file_str);
                    replace_punc(file_str);
                    remove_spaces(file_str,new_file_str);
                    /* Error - checking */
                    if( s_on == 1 && S_on == 1){
                        s_on = 1;
                        S_on = 1;
                        t_on = 1;
                        x_on = 1;
                        printf("Error - you cannot us -s and -S at the same time\n" );
                        exit(0);
                    }
                    if( s_on == 1){
                        shift = to_decode(shift);
                        printf("\n");
                        printf("shift = %d\n",shift);
                        printf("\n");
                        if( n_on == 0 && file_out == 0){ /* if both -O and -n arent there print to stdout*/
                            printf("Decoded Message: \n" );
                            decoded_message = numbers_shifting(file_str,shift); /* decode the message */
                            printf("%s\n",decoded_message);
                            printf("\n");
                            decoded_message = new_file_str;
                        }
                        else if ( file_out == 1){ /* if -O is there then print to file */
                            fprintf(f2,"Decoded Message: \n" );
                            decoded_message = numbers_shifting(file_str,shift);
                            fprintf(f2,"%s\n",decoded_message);
                            fprintf(f2,"\n");
                            decoded_message = new_file_str;
                        }
                    }
                    if(S_on == 1){
                        printf("\n");
                        printf("shift = %d\n",shift);
                        printf("\n");
                        if( n_on == 0 && file_out == 0){ /* if both -O and -n arent there print to stdout*/
                            printf("Encoded Message: \n");
                            encoded_message = numbers_shifting(file_str,shift); /* encode the message */
                            printf("%s\n",encoded_message);
                            printf("\n");
                            encoded_message = new_file_str;
                        }
                        else if ( file_out == 1){ /* if -O is there then print to file */
                            fprintf(f2,"Encoded Message: \n");
                            encoded_message = numbers_shifting(file_str,shift);
                            fprintf(f2,"%s\n",encoded_message);
                            fprintf(f2,"\n");
                            encoded_message = new_file_str;
                        }

                    }
                    if(x_on == 1){
                        double chi_sq = get_chi_sq(shift,file_str,new_file_str);
                        fprintf(f2, "\n");
                        fprintf(f2,"shift => chi_square(shift)\n");
                        int x;
                            for(x = 0; x < 26; x++){ /* loop for shift in ch_sq function, where shift is x */
                                chi_sq = get_chi_sq(x,file_str,new_file_str);
                                fprintf(f2,"%3d => %4.18lf\n",x, chi_sq);

                            }
                    }
                    if ( t_on == 1){
                        int * freq_table =  Text_freq(new_file_str);
                        fprintf(f2,"\n");
                        fprintf(f2,"c => Text_freq\n");
                        for( k = 0; k < 26; k ++){ /* 65 is ascii for a, so you add 0 to 65 to get letter a, and 65 + 1 = b, etc..*/
                            fprintf(f2,"'%c'\t=> %d\n",k+65,freq_table[k]); /* print freq_table for all letters */
                        }
                        fprintf(f2,"\n");
                        int numletter = letter_count(new_file_str); /* get the count of total letters in text */
                        fprintf(f2,"Number of letters in text = %d\n",numletter);
                        free(freq_table);
                    }


                    free(new_file_str);
                    free(file_str);
                    fclose(f2);
                }
        }
        if(file_out == 0){
                char c;
                int k;

                chop(file_str);
                replace_punc(file_str);
                remove_spaces(file_str,new_file_str);
                int shift = encode_shift(file_str,new_file_str);
                if(n_on == 1){
                    x_on = 0;
                    s_on = 0;
                    S_on = 0;
                    t_on = 0;
                }
                /* Error - checking */
                if( s_on == 1 && S_on == 1){
                    n_on = 1;
                    printf("Error - you cannot us -s and -S at the same time\n" );
                    exit(0);
                }
                if( s_on == 1){
                    shift = to_decode(shift);

                    printf("\n");
                    printf("shift = %d\n",shift);
                    printf("\n");
                    if( n_on == 0 && file_out == 0){
                        printf("Decoded Message: \n" );
                        decoded_message = numbers_shifting(file_str,shift);
                        printf("%s\n",decoded_message);
                        printf("\n");
                        decoded_message = new_file_str;
                    }

                }
                if(S_on == 1){

                    printf("\n");
                    printf("shift = %d\n",shift);
                    printf("\n");
                    if( n_on == 0 && file_out == 0){
                        printf("Encoded Message: \n");
                        encoded_message = numbers_shifting(file_str,shift);
                        printf("%s\n",encoded_message);
                        printf("\n");
                        encoded_message = new_file_str;
                    }

                }

                if(x_on == 1){
                    double chi_sq = get_chi_sq(shift,file_str,new_file_str);
                    printf("shift => chi_square(shift)\n");
                    int x;
                        for(x = 0; x< 26; x++){
                            chi_sq = get_chi_sq(x,file_str,new_file_str);
                            printf("%3d => %4.18lf\n",x, chi_sq);
                        }
                }
                if ( t_on == 1){
                    int * freq_table =  Text_freq(new_file_str);
                    printf("\n");
                    printf("c => Text_freq\n");
                    for( k = 0; k < 26; k ++){
                        printf("'%c' => %d\n",k+65,freq_table[k]);
                    }
                    printf("\n");
                    int numletter = letter_count(new_file_str);
                    printf("Number of letters in text = %d\n",numletter);
                    free(freq_table);

                }

                free(new_file_str);
                free(file_str);
        }


        return 0;
}
