#include<assert.h>
#include<stdio.h>

/*This function takes an integer greater than 0 and prints out each digit starting from 
the least significant to the most. It does this by using the remainder function to obtain eachindividual digit, print it, then use the integer divide function to obtain the next digit.*/
int printDecimalDigits(int n)
{
  if (n <= 0) return -1;
  int mem;
  while (n != 0) {
    mem = n % 10;
    printf("%d\n", mem);
    n = n / 10;
  }
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
  
  
  
  
