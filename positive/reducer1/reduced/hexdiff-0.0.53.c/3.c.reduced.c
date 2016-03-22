int lignes[14];
int popup_aide_largmax;
popup_aide() {
  int foo = 0;
  while (1) {
    if (!(foo < sizeof lignes / sizeof(int)))
      goto while_break;
    airac_observe(lignes, foo);
    popup_aide_largmax = foo++;
  }
while_break:
  ;
}
