#include<stdio.h>
#include<assert.h>

/*This function takes an integer input and uses a for loop in order to find the integer's factorial. It does this by itterating through the loop the same number of times as the integer and multplying the total by one value less than the current number each time.*/
int factorial(int n,int *f)
{
  int i, tot = 1, curr = n;
  if (f == NULL || n < 0) return -1;
  else if (n == 0 || n == 1) {
    *f = 1;
    return 0;
  }
  else {
    for (i = 0; i < n; i ++) {
      tot = tot * curr;
      curr = curr -1;
	}
    *f = tot;
    return 0;
  }
}

/*The following assertion statements are used to check the possible scenarios the function can take and to check if one of the scenarios will break the function.*/   
int main(void)
{
  int err, f;
  err = factorial(5,&f);
  assert(err == 0);
  assert(f == 120);
  err = factorial(-3,&f);
  assert(err == -1);
  assert(f == 120);
  err = factorial(0, &f);
  assert(f == 1);
  assert(err == 0);
  err = factorial(12,NULL);
  assert(err == -1);
  assert(f == 1);
  return 0;
}
