int main_got;
main() {
  char sniff[8];
  int tmp___12;
  main_got++;
  while (1) {
    if (!(main_got < 5))
      goto while_break___1;
    tmp___12 = main_got++;
    airac_observe(sniff, tmp___12);
  }
while_break___1:
  main_got--;
}
