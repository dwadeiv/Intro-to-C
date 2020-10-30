#include <assert.h>
#include <stdio.h>
void swap3(int *a, int *b, int *c)
{
  assert(a != 0 && b != 0);
  assert(c != 0);
  int t = *a;
  *a = *c;
  *c = *b;
  *b = t;
}

int main(void)
{
  int a = 6, b = 7, c = 12;
  swap3(&a, &b, &c);
  assert(a == 12 && b ==6);
  assert(c == 7);
  return 0;
}
  

  
  
    
