#include<stdio.h>
#include<assert.h>

/*This function takes two integre parameters and one pointer, finds the value of the first integer powered by the second one, and stores the value in a pointer. First it checks the base conditions are met, the interate through a for loop the samwe number of times as the second integer, each time multplying the first integer with itself, then giving a total count after the loop is terminated.*/
int power(int a, int n, int *p)
{
  int tot = 1,i;
  if (n < 0 || p == NULL) return -1;
  else if (n == 0) {
    *p = 1;
    return 0;
  }
  else {
    for (i=0 ; i < n; i++){
      tot = tot * a;
    }
    *p = tot;
    return 0;
  }
}
   
/*Assertion statements are put in the main to test and try to break the power function. It gives all possible scenarios that might break the program, and uses the assertion operator to check if the function retuern and stored the correct values for that given instance.*/
int main(void)
{
  int p, err;
  err = power(3,4,&p);
  assert(err == 0);
  assert(p == 81);
  err = power(-3,4,&p);
  assert(err == 0);
  assert(p == 81);
  err = power(-3,3,&p);
  assert(err == 0);
  assert(p == -27);
  err = power(3,-3,&p);
  assert(err == -1);
  err = power(2,4,NULL);
  assert (err == -1);
  err = power(9,0,&p);
  assert(err == 0);
  assert(p == 1);
  return 0;

}
  
