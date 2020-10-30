#include<stdio.h>
#include<assert.h>

int hasSubstring(char * str, char * substr)
{
  if(!str || !substr) return 0;
  int i, j;
  for ( i = 0; str[i] != '\0'; i ++) {
    for(j = 0; ;j++) {
      if(substr[j] == '\0') return 1;
      if(substr[j] != str[i+j]){
	break;
      }
      return 0;
    }
  }
}

int main(void)
{
  assert(hasSubstring("Hello universe!","lo"));
  assert(hasSubstring("Hello universe!","verse"));
  assert(hasSubstring("Hello universe!",""));
  assert(hasSubstring("",""));
  assert(!hasSubstring("Hello universe!","verses"));
  assert(!hasSubstring("Hello universe!","loun"));
  assert(!hasSubstring("Hello universe!","erse!!"));
  return 0;
  
}
