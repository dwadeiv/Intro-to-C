#include <assert.h>
int multipleof3(int n)
{
  if ((n % 3) == 0){
    return 1;
      }
  else {
    return 0;
      }
}

int main(void)
{
  int ret = multipleof3(9);
  assert(ret = 1);
  ret = multipleof3(8);
  assert (ret == 0);
  ret = multipleof3(-9);
  assert (ret == 1);
  ret = multipleof3(-25);
  assert (ret == 0);
  ret = multipleof3(2187);
  assert (ret == 1);
  return 0;
    }


   
  
