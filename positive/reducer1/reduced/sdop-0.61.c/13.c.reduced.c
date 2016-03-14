int fdata_type[4];
int fdata_type_count = sizeof(int), parse_font_tmp___13;
parse_font() {
  int k = 0;
  while (1) {
    if (!(k < fdata_type_count))
      goto while_break___4;
    if (parse_font_tmp___13)
      airac_observe(fdata_type, k);
    k++;
  }
while_break___4:
  ;
}
