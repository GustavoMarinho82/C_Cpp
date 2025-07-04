#include <stdio.h> 

#include "mypushpop.h"
#include "mygetop.h"
#include "myatof.h"

#ifndef MAXOP
#define MAXOP 100    /* max size of operand or operator */
#endif
#ifndef NUMBER
#define NUMBER '0'   /* signal that a number was found */
#endif

main()      /* reverse Polish calculator */
{
   int type;
   double op2;
   char s[MAXOP];
	printf("\nDigite uma fórmula em notação polonesa reversa.\nPor exemplo, para calcular 10+20x30, é preciso digitar 10 20 + 30 *\nPara sair, digite Ctrl+D.\n");
   while ((type = getop(s)) != EOF) 
   {
      switch (type) {
         case NUMBER:
            push(atof(s));
         break;

         case '+':
            push(pop() + pop());
         break;

         case '*':
            push(pop() * pop());
         break;

         case '-':
            op2 = pop();
            push(pop() - op2);
         break;

         case '/':
            op2 = pop();
            if (op2 != 0.0)
               push(pop() / op2);
            else
               printf("error: zero divisor\n");
         break;

         case '\n':
            printf("\t%.8g\n", pop());
				printf("\nDigite uma fórmula em notação polonesa reversa.\nPara sair, digite Ctrl+D.\n");
         break;

         default:
            printf("error: unknown command %s\n", s);
         break;
      }
   }
   return 0;
}
