int tris[1][1][26];
main() {
  int c1, c2, c3 = 0;
  while (1) {
    if (!(c3 < 26))
      goto while_break___10;
    airac_observe(tris[c1][c2], c3);
    c3++;
  }
while_break___10:
  ;
}
