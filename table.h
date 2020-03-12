double EF[26];
#define MAXSIZE 500
struct Record {
    char string[24];
    double value[24];
    char long_char[144];
    int num[12];
    // struct Record *next;
};

typedef struct Record Record;

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
int encode_shift(char* file_str,char* new_file_str);
char* malloc_new_file ( char* file);
int replace_punc( char *line );
int chop ( char *line );
char* numbers_shifting(char* original, int shift);
Record * add_first(Record*, Record*);
Record* listToFile (Record*list, char* filename);
Record * fileToList(char * filename,int recNum);
int get_num_entries (char* filename);
int to_decode(int shift);
