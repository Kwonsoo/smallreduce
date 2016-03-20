void *parse_printer_record_tmp, *xmalloc_r;
int page_list_size, grow_array_size_needed;
void *xmalloc();
static *parse_printer_record();
printer_stats() {
  int tmp_printer = parse_printer_record();
  airac_observe(tmp_printer, 0);
}

int *parse_printer_record() {
  parse_printer_record_tmp = xmalloc();
  return parse_printer_record_tmp;
}

void *xmalloc(p1) {
  xmalloc_r = malloc(p1);
  return xmalloc_r;
}

grow_array(int *p1) {
  *p1 += 1000;
  grow_array_size_needed = *p1;
  xmalloc(grow_array_size_needed);
  grow_array(&page_list_size);
}
