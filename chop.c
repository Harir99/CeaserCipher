#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int chop ( char *line ) {
int last_character = strlen(line) - 1;
int i;
char len = strlen(line);

  while (len == 0) {
     line[last_character] = len++;
     line[last_character]+= (line[last_character] != '\n');
   }
   line[last_character] = '\0';
   return  0;
}
