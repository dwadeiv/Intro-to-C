#include<stdio.h>
#include<assert.h>

int strcnt(char *str)
{
  int j = 0;
  while (*str != '\0') {
    str ++;
    j++; 
  }
  return j-1;
}

int suffix(char *str, char *suf)
{
  if (!str || !suf) return 0;
  int strngcnt = strcnt(str), sufcnt = strcnt(suf), i = sufcnt,  j = 0;
  if(sufcnt > strngcnt) return 0;
  while (sufcnt >= 0){
    if(str[strngcnt] == suf[sufcnt]) {
      j++;
    }
    sufcnt--;
    strngcnt--;
  }
  if(i == j) return 1;
  return 0;
}


int main(void)
{
  int err;
  char strng[] = "wasted";
  char suf[] = "ed";
  err = suffix(strng, suf);
  assert(err == 1);
  return 0;
}
  
  
