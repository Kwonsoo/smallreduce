int serial_no_map[2048];
main() {
  int i = 0;
  if (!i)
    goto while_break;
  i++;
while_break:
  airac_observe(serial_no_map, i);
}
