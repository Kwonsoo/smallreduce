int *coClosed;
int coTotal;
void *initArrays_tmp___5;
initArrays() {
  int j;
  coTotal = 64;
  initArrays_tmp___5 = malloc(sizeof(int) * coTotal);
  coClosed = initArrays_tmp___5;
  j = 0;
  while (1) {
    if (!(j < coTotal))
      goto while_break;
    airac_observe(coClosed, j);
    j++;
  }
while_break:
  coTotal *= 2;
}
