int numOccur(int const a[], int n, int v, int *occ)
{
  if ( !a || !occ) return -1;
  if (n < 0) return -2;
  *occ = 0;
  int i;
  for (i = 0; i < n; i++) {
    if(a[i] == v) {
      *occ = *occ + 1;
    }
    
  }
  return 0;
}

int main(void)
{
  char a[], int n
}
  
  
  
