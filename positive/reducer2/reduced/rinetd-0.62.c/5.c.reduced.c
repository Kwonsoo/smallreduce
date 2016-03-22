char **coOutput;
int coTotal;
void *initArrays_tmp___10;
initArrays() {
  int j;
  coTotal = 64;
  initArrays_tmp___10 = malloc(sizeof(char *) * coTotal);
  coOutput = initArrays_tmp___10;
  j = 0;
  while (1) {
    if (!(j < coTotal))
      goto while_break;
    airac_observe(coOutput, j);
    j++;
  }
while_break:
  coTotal *= 2;
}
