int main_got;
main() {
  char sniff[8];
  int tmp___17;
  main_got++;
  while (1) {
    if (!(main_got < 4))
      goto while_break___2;
    tmp___17 = main_got++;
    airac_observe(sniff, tmp___17);
  }
while_break___2:
  main_got--;
}
