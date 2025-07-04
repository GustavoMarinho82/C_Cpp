#include <ctype.h>

#include "mychio.h"

#ifndef NUMBER
#define NUMBER '0'   /* signal that a number was found */
#endif

int getop(char s[])  /* getop: get next character or numeric operand */
{
   int i, c;
   while ((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';
   if (!isdigit(c) && c != '.') /* not a number */
      return c;
  
   i = 0;
   if (isdigit(c)) /* collect integer part */
      while (isdigit(s[++i] = c = getch()))
         ;
   if (c == '.') /* collect fraction part */
      while (isdigit(s[++i] = c = getch()))
         ;
   s[i] = '\0';
   if (c != '\4')
      ungetch(c);
   return NUMBER; /*if it is a NUMBER*/
}

