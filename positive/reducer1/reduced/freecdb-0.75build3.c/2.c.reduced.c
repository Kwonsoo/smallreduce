int main_tmp___11;
main() {
  long distance[11];
  int i = 0;
  while (1) {
    if (!(i < 11))
      goto while_break;
    airac_observe(distance, i);
    i++;
  }
while_break:
  main_tmp___11 = fmt_ulong();
  i = main_tmp___11;
}
