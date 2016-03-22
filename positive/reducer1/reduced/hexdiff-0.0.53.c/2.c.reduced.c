int lignes[14];
popup_aide_ligmax() {
  int foo = 0;
  while (1) {
    if (!(foo < sizeof lignes / sizeof(int)))
      goto while_break;
    airac_observe(lignes, foo);
    if (popup_aide_ligmax)
      foo++;
  }
while_break:
  ;
}
