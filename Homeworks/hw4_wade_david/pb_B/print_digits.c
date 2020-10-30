#include<assert.h>
#include<stdio.h>

/*This function takes an integer greater than 0 and prints out each digit starting from 
the most significant to the least. It does this by using the remainder function to obtain each individual digit starting from the last significant,then storing the digit into a variable, then use recursion with the parameter n being integer divided in order to obtain thenext digit. After all the digits have been obtained, the program will back track, printing each digit as it completes each iteration of the recursion*/
int printDecimalDigits(int n)
{
  if (n <= 0) return -1;
  int mem = n % 10;
  printDecimalDigits(n/10);
  printf("%d\n",mem);
  return 0;
}

int main(void)
{
  int rv;
  printf("299\n");
  rv = printDecimalDigits(299);
  assert(rv == 0);
  printf("-8\n");
  rv = printDecimalDigits(-8);
  assert(rv == -1);
  printf("0\n");
  rv = printDecimalDigits(0);
  assert(rv == -1);
  printf("123456789\n");
  rv = printDecimalDigits(123456789);
  assert(rv == 0);
  return 0;
}
