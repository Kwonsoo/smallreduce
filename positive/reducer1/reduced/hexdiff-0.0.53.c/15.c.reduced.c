extern lignes[14];
lignes_0_0() {
  int foo = 0;
  while (1) {
    if (!(foo < sizeof lignes / sizeof(int)))
      goto while_break;
    airac_observe(lignes, foo);
    fprintf("", lignes_0_0);
    foo++;
  }
while_break:
  ;
}
