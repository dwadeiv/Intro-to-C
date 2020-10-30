#include<assert.h>
#include<stdio.h>

/*This function takes an integer parameter and adds the squares of each indivual digit to create a sum.*/
int happySum(int n)
{
  if (n < 0) n = -n;
  int mem, sum = 0;
  while (n != 0) {
    mem = n % 10;
    sum += mem*mem;
    n = n / 10;
  }
  return sum;
}
/*This function takes an integer parameter and will constantle check if the parameter is equal to either 1 or 4, then calls the happySum function un til one of those conditions are met. If n == 1, then the number is Happy, if it equals 4, then the number is sad.*/
int isHappy(int n)
{
  if (n == 0) return 0;
  while (1) {
    if (n == 1) return 1;
    else if (n == 4) return 0;
    n = happySum(n);
  }
}
/*One for loop was added to the main function to test every integer between 0 and 100 to see which nes are happy or not. All intg=egers that are happy are then printed into a list*/
int main(void)
{
  int i,n;
  for (i = 0; i <= 1000; i++) {
    n = isHappy(i);
    if (n == 1) {
      printf("%d\n",i);
	}
  }
  return 0;
}
