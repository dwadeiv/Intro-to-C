#include<assert.h>
#include<stdio.h>

int whisper(char *msgIn, char *msgOut)
{
  if (!msgIn || !msgOut) return -1;
  while (*msgIn != '\0') {
    if ('A' <= *msgIn && *msgIn <= 'Z') {
      *msgOut = *msgIn - ('A' - 'a');
    }
    else {
      *msgOut = *msgIn;
	}
    msgIn ++;
    msgOut ++;
  }
  

  *msgOut = '\0';
  return 0;
}

int main(void)
{
  assert(whisper("HELLO","hello"));
  return 0;
}
	 
  
