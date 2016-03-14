int templates[6];
int template_count = sizeof templates / sizeof(int);
sdop_init_templates_tmp___0() {
  int i = 0;
  while (1) {
    if (!(i < template_count))
      goto while_break;
    airac_observe(templates, i);
    if (sdop_init_templates_tmp___0)
      i++;
  }
while_break:
  ;
}
