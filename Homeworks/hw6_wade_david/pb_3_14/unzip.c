#include <stdio.h>
#include <assert.h>

int unzip(int *a, int *b, int *c, int n)
{
  if (!a || !b || !c || n < 0) return -1;
  int i = 0;
  while(i < n) {
    if(i == 0) {
      * a = c[i];
      a++;
    }
    if((i % 2) == 0) {
      *a = c[i];
      a++;
    }
    if((i % 2) == 1) {
      *b = c[i];
      b++;
    }
    i++;
  }
  return 0;
}

int main(void)
{
  int c[] = {1,2,3,4,5,6};
  int a[3];
  int b[3];
  int err, n = 3;
  err = unzip(a, b, c, n);
  assert(err == 0);
  err = unzip(NULL, b, c, n);
  assert(err == -1);
  err = 3;
  err = unzip(a, NULL, c, n);
  assert(err == -1);
  err =3;
  err = unzip(a, b, NULL, n);
  assert(err == -1);
  err = 3;
  err = unzip(a, b, c, -9);
  assert(err == -1);
  return 0;
}
