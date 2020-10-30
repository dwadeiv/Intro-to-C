#include<stdio.h>
#include<assert.h>

int minmax(int *a, int n, int *min, int *max)
{
  if (!a || !min || !max) return -1;
  if (n <= 0) return -2;
  int cnt1 = a[0], cnt2 = a[0];
  int i;
  for (i = 1; i < n; i++) {
    if (cnt1 < a[i]) {
      cnt1 = a[i];
    }
    if (a[i] < cnt2) {
      cnt2 = a[i];
    }
  }
  *max = cnt1;
  *min = cnt2;
  return 0;
}

int main(void)
{
  int err, min, max;
  int a[] = {3,5,12,-9,-8,22,0};
  err = minmax(a, 7, &min, &max);
  assert(err == 0 && min == -9 && max == 22);
  err = minmax(NULL, 7, &min, &max);
  assert(err == -1);
  err = minmax(a, -7, &min, &max);
  assert(err == -2);
  err = minmax(a, 7, NULL, &max);
  assert(err == -1);
  err = 3;
  err = minmax(a, 7, &min, NULL);
  assert(err == -1);
  return 0;
}
