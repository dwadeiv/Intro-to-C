#include<stdio.h>
#include<ctype.h>

int main()
{
  char c;
  int length = 0, count = 0, totallen = 0;
  while(scanf("%c", &c) != EOF) {
    if (isspace(c) == 0) {
      length ++;
    }
    else {
      if (length != 0) {
	totallen += length;
	length = 0;
	count ++;
      }
    }
  }
  int avg = totallen / count;
  printf("The mean is %d \n", avg);
  return 0;
}
