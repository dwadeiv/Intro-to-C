#include<stdio.h>
#include<assert.h>

int xvowelize(char * in, char * out)
{
  if (!in || !out) return -1;
  while (*in != '\0') {
    if(*in != 'A' && *in != 'a' && *in != 'E' && *in != 'e' && *in != 'I' && *in != 'i' && *in != 'O' && *in != 'o' && *in != 'U' && *in != 'u') {
      *out = *in;
      out ++;
    }
    in ++;
  }
  *out = '\0';
  return 0;
}

int main(void)
{
  char str[] = "Hello universe!";
  char out[32];
  int err = xvowelize(str, out);
  assert(!err);
  printf("%s\n%s\n", str , out);
  err = xvowelize(NULL, out);
  assert(err == -1);
  err = 3;
  err = xvowelize(str, NULL);
  assert(err == -1);
  return 0;
}
