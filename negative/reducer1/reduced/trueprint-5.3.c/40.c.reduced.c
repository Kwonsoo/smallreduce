void *parse_printer_record_tmp, *xmalloc_r;
int grow_array_size_needed;
void *xmalloc();
int *parse_printer_record();
printer_stats() {
  int tmp_printer = parse_printer_record();
  airac_observe(tmp_printer, 0);
}

int *parse_printer_record() {
  parse_printer_record_tmp = xmalloc();
  return parse_printer_record_tmp;
}

void *xmalloc() { return xmalloc_r; }

grow_array(p1) {
  grow_array_size_needed = p1;
  xmalloc_r = malloc(grow_array_size_needed);
  grow_array(sizeof(int));
}
