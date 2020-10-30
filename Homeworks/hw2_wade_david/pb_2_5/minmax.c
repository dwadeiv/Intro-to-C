#include <assert.h>
int minmax(int a, int b, int * min, int * max)
{
  if (a < b)
    {
    * min = a;
    * max = b;
    }
  else if (a == b)
    {
      * min = a;
      * max = a;
    }
  else
    {
      * max = a;
      * min = b;
    }
  return 0;
} 
	 
int main(void)
{
  int min;
  int max;
  minmax (8, 9, & min, & max);
  assert (min == 8 && max ==9);
  minmax (-8, -9, & min, & max);
  assert (min == -9 && max == -8);
  minmax (8, 8, & min, & max);
  assert (min == max);
  minmax (-8, -8, &min, & max);
  assert (min == max);
  return 0;


}
  
