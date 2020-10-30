#include <stdio.h>
#include <assert.h>

/* This function takes the integer from the other factroial function, checks to see if it equeals either 0 or 1, then continues to call itself until the return is the desired factorial.*/
int _factorial(int n) 
{
  if (n == 1 || n ==0) return 1;
  else {
    return n * _factorial(n-1);
  }
}

/* This function checks whether the requierments of the input needing to be above zero and for f to have a valid address, returns -1 if conditions are meant, then will procede to call the other factorial function to calculate the factorial of the given integr. Once the value is obtained, the program will return to this function, return 0, then will return baxck to main.*/
int factorial(int n, int *f) 
{
  if (f == NULL || n < 0) return -1;
  *f = _factorial(n);
  return 0;
}

int main(void)
{
  int err, n;
  /*The purpose of the following assert statements are to check if the factorial functions run the way they need to and the proper values were assigned to where they needed to be.*/
  err = factorial(4,&n);
  assert(err == 0);
  assert(n == 24);
  err = factorial(0,&n);
  assert(err == 0);
  assert(n == 1);
  err = factorial(-4,&n);
  assert(err == -1);
  assert(n == 1);
  err = factorial(3,NULL);
  assert(err == -1);
  assert(n == 1);
  return 0;
}
  
   








 
