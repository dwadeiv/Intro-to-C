#include <stdio.h>
#include <assert.h>

int strcmp2(char *str1, char *str2)
{
  if (!str1 || !str2) return 0;
  while(*str1 != '\0' || *str2 != '\0') {
    if (*str2 > *str1) return -1;
    if (*str2 < *str1) return 1;
    str1 ++;
    str2 ++;
  }
  return 0;
}

int main(void)
{
  printf("aardvark, aardwolf %d\n", strcmp("aardvark", "aardwolf"));
  printf("AVAST, avast %d\n", strcmp("AVAST", "avast"));
  printf("ahoy, ahoy %d\n", strcmp("ahoy", "ahoy"));
  printf("Watch for aardvarks!, " "Watches aren't for aardwolves. %d\n", strcmp("Watch for aardvarks!", "Watches aren't for aardwolves."));
  return 0;
}
