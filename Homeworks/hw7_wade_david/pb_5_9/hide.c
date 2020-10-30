#define SHIFT 4
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
  int shift;
  if(strcmp("-encrypt",argv[1]) == 0 || argc == 1) {
    shift = SHIFT;
  }
  else if(strcmp("-decrypt", argv[1])) {
    shift = 26 - SHIFT;
  }
  else {
    printf(" ");
    return -1;
  }
  char c;
  while(scanf("%c", &c) != EOF) {
    if('a' <= c && c <= 'z') {
      c = 'a' + ((c-'a' + shift) % 26);
    }
    else if ('A' <= c && c <= 'Z') {
      c = 'A' + ((c - 'A' + shift) % 26);
      printf("%c\n",c);
    }
  }
  return 0;
}
