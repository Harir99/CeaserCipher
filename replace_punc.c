#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int replace_punc( char *line ) {
   int i, len;
   unsigned int punc;
   len = strlen(line);

   for (i = 0; i < len; i++) {
      punc = line[i];

      if (punc > 32 && punc < 48) {
         line[i] = ' ';

      } else if (punc > 57 && punc < 65) {
	 line[i] = ' ';

      } else if (punc > 90 && punc < 97) {
	 line[i] = ' ';

      } else if (punc > 122 && punc < 256) {
	 line[i] = ' ';
      }
   }
   return 0;
}
