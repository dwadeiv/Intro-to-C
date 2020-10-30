#include <stdio.h>
#include <assert.h>
/*This function takes an integer and then uses a while loop to obtain that number's factorial. This is done by iterating through the while loop the same number of times as the integer, each time multiplying the previous number with the next lowest one. it then assigns the total to the pointer.*/
int factorial(int n, int *f)
{
  int curr=n, tot = 1;
  if (f == NULL || n < 0) return -1;
  else if (n == 0 || n == 1){
    *f = 1;
    return 0;}
  else {
    while (0 < curr){
      tot = tot * curr;
      curr = curr -1;
    }}
  *f = tot;
  return 0;
}

int main(void)
/*The following assertion statements are used to check the possible scenarios the function can take and to check if one of the scenarios will break the function.*/
{
  int err, f;
  err = factorial(4,&f);
  assert(f == 24);
  assert(err == 0);
  err = factorial(0,&f);
  assert(f == 1);
  assert(err == 0);
  err = factorial(-5,&f);
  assert(f ==1);
  assert(err == -1);
  err = factorial(0,NULL);
  assert(f == 1);
  assert(err == -1);
  err = factorial(6,&f);
  assert(f == 720);
  assert(err == 0);
  return 0;
}
  
	
      
  
