#include<stdio.h>
#include<assert.h>

int mean(int *a, int len, int *mn)
{
  if (len <= 0 || !mn || !a) return -1;
  int i, cnt = 0;
  for (i = 0; i < len; i++) {
    cnt += a[i];
  }
  *mn = cnt/len;
  return 0;
}

int main(void)
{
  int a[9] = {1,2,3,4,5,6,7,8,9}, err, mn;
  err = mean(a, 9, &mn);
  assert(err == 0 && mn == 5);
  err = mean(NULL, 9, &mn);
  assert(err == -1);
  err = 3;
  err = mean(a, -9, &mn);
  assert(err == -1);
  err = 3;
  err = mean(a, 9, NULL);
  assert(err == -1);
  return 0;
}
