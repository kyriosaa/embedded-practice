#include <stdio.h>

int main() {
    /*

     + (addition)
     - (subtraction)
     * (multiplication)
     / (division)
     % (modulus)
     ++ (increment by 1)
     -- (decrement by 1)

    */

   int x = 8;
   int y = 5;

   float z = x / (float) y; // because division is weird

   printf("%f\n", z);

   /*----------------------------------------------------------------------------------*/

   // augmented assignment operators = used to replace a statement where an operator
   //                                  takes a variable as one of its arguments
   //                                  and then assigns the result back to the same variable
   //                                  x = x + 1
   //                                  x += 1

   // x = x + 2;
   x += 2;

   printf("%d\n", x);

   x *= 3;

   printf("%d\n", x);

   return 0;
}