void *parse_printer_type_tmp, *xmalloc_r;
int page_list_size, grow_array_size_needed;
void *xmalloc();
int *parse_printer_type();
printer_stats() {
  int tmp_type = parse_printer_type();
  airac_observe(tmp_type, 0);
}

int *parse_printer_type() {
  parse_printer_type_tmp = xmalloc();
  return parse_printer_type_tmp;
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
