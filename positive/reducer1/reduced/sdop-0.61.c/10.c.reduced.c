int fdata_family[3];
int fdata_family_count = sizeof fdata_family / sizeof(int), parse_font_tmp___8;
parse_font() {
  int k = 0;
  while (1) {
    if (!(k < fdata_family_count))
      goto while_break___2;
    if (parse_font_tmp___8)
      airac_observe(fdata_family, k);
    k++;
  }
while_break___2:
  ;
}
