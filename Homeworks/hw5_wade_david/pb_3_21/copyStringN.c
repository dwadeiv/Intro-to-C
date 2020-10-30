int copyStringN(char *in, char *out, int n)
{
  if (in == NULL || out == NULL) return -1;
  int i;
  for(i = 0; i < n-1; i++) {
    out[i] = in[i];
    if (in[i] == '\0') return 0;
  }
  out[i] = '\0';
  if (in[i] == '\0') return 0;
  return -2;
}
