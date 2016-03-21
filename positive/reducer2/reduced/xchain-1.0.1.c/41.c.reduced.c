char backcol[10];
draw_screen() {
  int i = 1;
  while (1) {
    if (!i)
      goto while_break___0;
    if (i < 3)
      airac_observe(backcol, i);
    i++;
  }
while_break___0:
  i = 0;
}
