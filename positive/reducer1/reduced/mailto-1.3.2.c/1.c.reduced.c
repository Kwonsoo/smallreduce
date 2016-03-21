char mailto_nptr;
mailto() {
  char *ptr = getenv("");
  airac_observe(ptr, 0);
  mailto_nptr = strchr(ptr, '\n');
  ptr = mailto_nptr;
}
