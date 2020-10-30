#include<assert.h>
#include<stdio.h>
/*This code only works for a few test cases. Not finished.*/
int isqrt(int n, int *isr)
{
  if (n < 0 || isr == NULL) return -1;
  int i = 0, mem, count = 0;
  while(1) {
    mem = i*i;
    if (mem >= n) {
      *isr = count-1;
      return 0;
    }
    count ++;
    i++;
  }
}

int main(void)
{
  int rev, isr;
  rev = isqrt(3,NULL);
  assert(rev == -1 && isr == 8);
  rev = isqrt(5,&isr);
  assert(rev == 0 && isr == 2);
  rev = isqrt(80,&isr);
  assert(rev == 0 && isr == 8);
  rev = isqrt(-9,&isr);
  assert(rev == -1 && isr == 8);
  return 0;
}
  
  
    
  
