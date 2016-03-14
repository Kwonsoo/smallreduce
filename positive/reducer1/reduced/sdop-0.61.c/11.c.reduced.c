double object_write_image_bb[4];
object_write_image() {
  double *bb = object_write_image_bb;
  int i = 0;
  while (1) {
    if (!(i < 4))
      goto while_break___0;
    airac_observe(bb, i);
    i++;
  }
while_break___0:
  ;
}
