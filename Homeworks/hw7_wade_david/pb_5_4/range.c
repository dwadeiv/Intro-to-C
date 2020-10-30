#include<stdio.h>

int main()
{
  int low, high, rng;
  int c;
  int rc = scanf("%d",&c);
  if (rc != 1){
    printf("Please enter numbers only\n");
    return -1;
  }
  high = c;
  low = c;
  while ((rc = scanf("%d", &c)) != EOF){
    if(rc != 1){
      printf("Please enter numbers only");
      return -1;
    }

    if (high < c) {
      high = c;
    }
    else if (c < low) {
      low = c;
    }
  }
  rng = high - low;
  printf("Range = %d\n",rng);
  return 0;
}
