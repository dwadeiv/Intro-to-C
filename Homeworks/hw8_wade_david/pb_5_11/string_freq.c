/*Look at page 108 for help on this problem*/
/*Incomplete program, will try and turn in late finished copy tomorrow*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void printDistribution(int * nOccur, int sz, int nTrials) {
  if (!nOccur) return;
  int i, j;
  for(i = 0; i < sz; i ++) {
    int percent = (100 * nOccur[i]) / nTrials;
    printf("%2d %2d", i, percent);
    for(j = 0; j < percent; j ++) {
      printf("*");
    }
    printf("\n");
  }
}

int main( int argc, char const * const argv[])
{
  int numarg = argc;
  if(argc != 3 && argc != 2 && argc == EOF) {
    printf("Please enter two arguments into the command line\n");
    return -1;
  }
  int c = 32, count = 0, rc;
  if(argc == 1) c = 32;
  else if((strcmp("-s", argv[1]) != 0) && argc > 1) {
    printf("Invalid input \n");
    return -1;
  }
  else if((strcmp ("-s", argv[1]) == 0) && argc != 3) {
    printf("Invalid input \n");
    return -1;
  }
  if (argc == 3) {
    
  }
}
