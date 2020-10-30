#include <stdio.h>

int main()
{
  int count = 0;
  char c, rc = scanf("%c",&c);
  while (rc = scanf("%c", &c) != EOF) {
    if(rc == 'A' || rc == 'a' || rc == 'E' || rc == 'e' || rc == 'I' || rc == 'i' || rc == 'O' || rc == 'o' || rc == 'U' || rc == 'u') {
      count ++;
    }
  }
  printf("The number of vowels is %d\n",count);
  return 0;
}
