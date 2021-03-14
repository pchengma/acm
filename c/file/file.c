#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
   FILE *fp = NULL;
   fp = fopen("buffs.txt", "wb");
   for (i = 0; i < p; ++i) {
       for (j = 0; j < k + 3; ++j) {
           for (l = 0; l < len; ++l) {
               fprintf(fp, "%d\t", buffs[i][j * len + l]);
           }
       }
       fprintf(fp, "\n");
   }
  
}

