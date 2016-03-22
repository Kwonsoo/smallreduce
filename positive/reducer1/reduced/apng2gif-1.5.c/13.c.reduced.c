struct __anonstruct_box_28 {
  int b0;
} bigcube[1][1][128], ConvertTo8bit_cube;
int WuCut_cutb;
WuMaximize(int *p1) { *p1 = -1; }

WuCut(struct __anonstruct_box_28 *p1) {
  WuMaximize(&WuCut_cutb);
  p1->b0 = WuCut_cutb;
}

ConvertTo8bit() {
  int i, j, k = 0;
  while (1) {
    if (!(k < 128))
      goto while_break___4;
    airac_observe(bigcube[i][j], k);
    k++;
  }
while_break___4:
  WuCut(&ConvertTo8bit_cube);
  k = ConvertTo8bit_cube.b0;
}
