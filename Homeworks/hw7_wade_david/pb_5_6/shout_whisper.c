#include<stdio.h>

int main(int argc, char * argv[])
{
  char c, s, out;
  char rc = scanf("%c", &s);
  if (sscanf(argv[1], "%c", &c) != 1) {
    printf("Expect either s or w input");
    return -1;
  }
  else if (c != 's' || c != 'w') {
    printf("Expect either s or w input");
    return -1;
  }
  else if (rc != 1) {
    printf("Expected character, not integer for argument");
    return -1;
  }
  if (c == 'w') {
    while ((rc = scanf("%c", &s)) != EOF) {
      if(rc != 1) {
	printf("Expected character, not integer for argument");
	return -1;
      }
      if('A' <= s && s <= 'Z') {
	out = s - ('A' - 'a');
	printf("%c", out);
      }
      else {
	out = s;
	printf("%c", out);
      }
    }
  }
  if (c == 's') {
    while ((rc = scanf("%c", &s)) != EOF) {
      if(rc != 1) {
	printf("Expected character, not integer for argument");
	return -1;
      }
      if('a' <= s && s <= 'z') {
	out = s + ('A' - 'a');
	printf("%c", out);
      }
      else {
	out = s;
	printf("%c", out);
      }
    }
    return 0;
  }
}
