/*!
 * @file
 * @brief Generates Roman Numerals from
 */

#include <stdio.h>
#include "RomanNumeral.h"
#include <string.h>


static char * Append(char *output, const char *toAppend)
{
   return output + sprintf(output, "%s", toAppend);
}

void RomanNumeral_Convert(unsigned input, char *output)
{
   char I[] = "I";
   char V[] = "V";
   char X[] = "X";
   char L[] = "L";
   char C[] = "C";
   char D[] = "D";
   char M[] = "M";


   int i = input%10;
   int x = (input%100) / 10;
   int c = (input%1000) / 100;
   int m = (input%10000) / 1000;
   int j;

   output[0] = '\0';

   // This is just a special case because I don't know the continuation for M.
   for (j = 0; j < m; j++) {
      strcat(output, M);
   }

   helper(output, c, C, D, M);
   helper(output, x, X, L, C);
   helper(output, i, I, V, X);

}


void helper (char* output, int placevalue, char* small, char* five, char* big) {
   int j;
   if (placevalue == 9) {
      strcat(output, small);
      strcat(output, big);
      placevalue = placevalue - 9;
   }
   if (placevalue == 4) {
      strcat(output, small);
      strcat(output, five);
      placevalue = placevalue - 4;
   } else if (placevalue >= 5) {
      strcat (output, five);
      placevalue = placevalue - 5;
   }
   for (j = 0; j < placevalue; j++) {
      strcat(output, small);
   }
}

