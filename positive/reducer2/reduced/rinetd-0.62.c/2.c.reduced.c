char **coInput;
int coTotal;
void *initArrays_tmp___9;
initArrays() {
  int j;
  coTotal = 64;
  initArrays_tmp___9 = malloc(sizeof(char *) * coTotal);
  coInput = initArrays_tmp___9;
  j = 0;
  while (1) {
    if (!(j < coTotal))
      goto while_break;
    airac_observe(coInput, j);
    j++;
  }
while_break:
  coTotal *= 2;
}
