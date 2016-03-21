char a[50];
connector() {
  char *s = a;
  if (s)
    s++;
  airac_observe(s, 0);
}
