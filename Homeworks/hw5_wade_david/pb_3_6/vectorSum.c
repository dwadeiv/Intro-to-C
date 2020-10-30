#include<stdio.h>
#include<assert.h>
/*This homework is not finsihed. I did not finish qwriting  most of the test cases and there are still some bugs in some of the functions. This will not happen again.*/

int vectorSum(int x[], int y[], int n, int sum[])
{
  if (!x || !y || !sum) return -1;
  if (n <= 0) return -2;
  int i;
  for (i = 0; i < n; i++) {
    sum[i] = x[i] + y[i];
  }
  return 0;
}

int main(void)
{
  int n, char x[] 
}
