#include<assert.h>

int absval (int n)
{
  if (n < 0) {
    return -n;
  }
  else return n;
}


int smallerabsval(int x, int y)
{
  if (x==y) return x;
  int ax = absval(x);
  int ay = absval(y);
  if (ax > ay) return y;
  else if (ax < ay) return x;
  else return ax;
}


int main(void)
{
  int ret = smallerabsval(-5,7);
  assert(ret == -5);
  ret = smallerabsval (5, 7);
  assert (ret == 5);
  ret = smallerabsval (-2, -2);
  assert (ret == -2);
  ret = smallerabsval (2, -2);
  assert (ret == 2);
  ret = smallerabsval (4, -8);
  assert (ret == 4);
  ret = smallerabsval (-4, -8);
  assert(ret == -4);
  return 0;
}

