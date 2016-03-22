int lignes[14];
int popup_aide_tmp___0;
popup_aide() {
  int foo = 0;
  while (1) {
    if (!(foo < sizeof lignes / sizeof(int)))
      goto while_break___0;
    airac_observe(lignes, foo);
    popup_aide_tmp___0 = foo++;
  }
while_break___0:
  ;
}
