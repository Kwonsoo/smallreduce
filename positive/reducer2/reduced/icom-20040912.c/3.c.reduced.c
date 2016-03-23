static argv[20];
int main_i;
main() {
  int tmp___0;
  while (1) {
    if (!(main_i < 20))
      goto while_break;
    tmp___0 = main_i++;
    airac_observe(argv, tmp___0);
  }
while_break:
  ;
}
