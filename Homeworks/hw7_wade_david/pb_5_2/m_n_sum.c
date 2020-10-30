#include<stdio.h>

int main(int argc, char * argv[])
{
  int n, m, i , sum = 0;
  if (argc != 3) {
    printf("Expected two positive arguments \n");
    return -1;
  }
  else if (sscanf(argv[1], "%d", &m) != 1) {
    printf("Expected positive integer with first argument\n");
    return -1;
  }
  else if (sscanf(argv[2], "%d", &n) != 1) {
    printf("Expected positive integer with second argument\n");
    return -1;
  }
  else if ( m <= 0 || n <= m || n <= 0) {
    printf("Expected two positive arguments with the first argument needing to be less than the second argument\n");
    return -1;
  }
  for( i = m; i <= n; i++) {
    sum = sum + i;
  }
  printf("The sum = %d\n", sum);
  return 0;
}
