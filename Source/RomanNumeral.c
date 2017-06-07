/*!
 * @file
 * @brief Generates Roman Numerals from
 */

#include "RomanNumeral.h"
#include <stdio.h>
#include <string.h>

void RomanNumeral_Convert(unsigned input, char *output)
{
   char I[] = "I";
   char V[] = "V";
   char X[] = "X";
   char L[] = "L";
   char C[] = "C";
   char D[] = "D";
   char M[] = "M";
   int i = input % 10;
   int x = (input % 100) / 10;
   int c = (input % 1000) / 100;
   int m = (input % 10000) / 1000;
   int j;

   output[0] = '\0';
   // This is just a special case because I don't know the continuation for M.
   for(j = 0; j < m; j++)
   {
      strcat(output, M);
   }

   appendLogic(output, c, C, D, M);
   appendLogic(output, x, X, L, C);
   appendLogic(output, i, I, V, X);
}

static void appendLogic(char *output, int placeValue, char *small, char *five, char *big)
{
   int j;
   if(placeValue == 9)
   {
      strcat(output, small);
      strcat(output, big);
      placeValue = placeValue - 9;
   }
   if(placeValue == 4)
   {
      strcat(output, small);
      strcat(output, five);
      placeValue = placeValue - 4;
   }
   else if(placeValue >= 5)
   {
      strcat(output, five);
      placeValue = placeValue - 5;
   }
   for(j = 0; j < placeValue; j++)
   {
      strcat(output, small);
   }
}

