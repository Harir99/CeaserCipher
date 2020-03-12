----------------------
PROGRAM(s) NAME: frequency_table.c , decode.c and  copy_record.c
----------------------
AUTHOR'S NAME
--------------
Harir Al-Rubaye

INTRODUCTION
------------
The first program - frequency_table.c :
it automate the determining of the shift used in the Caesar encoding,
you will need to determine the frequency in the text of each letter in the alphabet, which is what this program does.

The Second Program - decode.c :
Takes an input file, Computes the character/letter count summary and frequency table and use them to compute chi sq values
for all shift, automatically deciding the shift value based on the smaller chi sq value and uses it to
the Caesar shift value to decode the message, and prints it to stdout. As well as it computes the original
Caesar shift value used to encode the message, and prints it to stdout.

The third program - copy_record :
If a text field is encrypted, it is using a Caesar cipher encryption with the same shift as used in encoding a
companion file stored in the same directory, which hold English text that contains at least 100 characters. then
it will copy the records across to a new file, possibly in reverse order, with the fields decoded using
the shift discovered using the accompanying text file.

Note: I made a header file called table.h, instructions weren't clear about the whether to output binary format or text, as in assignment doc it says to output to file as binary fomat, but example uses text, so i output text to stdout and binary format to output file.

NOte #2 : press Ctrl + D ( ^d) on a new line to stop typing in stdin 

COPY_RECORD REVERSE METHOD
---------------------------
To reverse the records I started from the end of the records and printed one by one till we reached the top,
and i did that by reversing the loop:

For example instead of "for (k = 0; k < number; k++)" I used "for (k = number-1; k >= 0; k--) " to reverse it
where number is the number of entries of the file, which is calculated in get_num_entries function , that
divides the size of the file by the size of the records.

FUNCTIONS INCLUDED
-------------------

int file_size( FILE *fp);
int letter_count(char* string);
void print_frequency_table (int* counter);
void remove_spaces(char string[100], char stringNew[100]);
int* Frequency_table (char* array);
int chars_count(char* string);
int* Text_freq (char* file_contents);
char encode (char c, int shift);
int offset (char c);
char* read_file (char* file);
double get_chi_sq(int shift, char * file_str,char* new_file_str);
int decode_shift(char* file_str,char* new_file_str);
char* malloc_new_file ( char* file);
int replace_punc( char *line );
int chop ( char *line );
char* numbers_shifting(char* original, int shift);
Record * add_first(Record*, Record*);
Record* listToFile (Record*list, char* filename);
Record * fileToList(char * filename,int recNum);
int get_num_entries (char* filename);

STRUCTURES INCLUDED
-------------------
struct Record {
    char string[24];
    double value[24];
    char long_char[144];
    int num[12];
    // struct Record *next;
};

RUNNING THE PROGRAM
-------------------
To compile the program type the following on your terminal:
    $ make all

    or if you want to compile frequency_table.c alone:
    $ make frequency_table

    or if you want to compile decode.c alone:
    $ make decode

     or if you want to compile copy_record.c alone:
    $ make copy_record

To run frequency_table.c:
    $ ./frequency_table -F input_file_name

To run decode.c:
    you can use a multiple combinations such as:
    with any combination of the following flags -s, -S, -t, -x, and -n, as long as to you dont have -S and -s together;
    for instance:
    $ ./decode –stx –F myfile.txt –O decodedfile.txt
    $ ./decode –Stx –F myfile.txt –O decodedfile.txt
    $ ./decode –st –F myfile.txt –O decodedfile.txt
    $ ./decode –sx –F myfile.txt –O decodedfile.txt
    $ ./decode –tx –F myfile.txt –O decodedfile.txt
    $ ./decode –stxn –F myfile.txt ( when n included the output file is not printed to stdout)
    You can also run the program with only input file(takes from stdin), only output file(prints to stdout)
    or without either of them:
    $ ./decode –stx –F myfile.txt
    $ ./decode –stx –O decodedfile.txt
    $ ./decode –stx

Note : make sure to add the -F input_file, otherwise you will get an error informing you to add it.
 ( you need an input file ).

To run copy_record.c:
    you can use the following flags:
    -F The name of the input file.
    -O The name of the output file after decoding. (If missing prints to  stdout.)
    -D The name of the text file to be used to find the Caesar cipher shift to be used to decode the text fields
    of each record. If missing, the text fields are left undecoded when copied.
    -r Copy the records in reverse order. If missing, the records are copied in order.

        Overall you can run the following scenarios :
    $ ./copy_record -r -D companion_file -F input_file -O output_file
    $ ./copy_record -D companion_file -F input_file -O output_file
    $ ./copy_record -F input_file -O output_file
    $ ./copy_record -F input_file

After that to get rid of the *.o files:
    $ make clean
