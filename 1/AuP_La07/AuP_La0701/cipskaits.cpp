int cipskaits(int n) {
  if (n < 0)
    n = -n;

  int cskaits = 0;

  do {
    cskaits++;
    n = n/10;
  }while(n>0);

  return cskaits;
}
