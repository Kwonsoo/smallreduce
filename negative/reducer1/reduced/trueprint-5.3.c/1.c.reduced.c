void *xmalloc_r, *expand_string_tmp;
int page_list_size, grow_array_size_needed, output_buffer;
xmalloc(p1) { xmalloc_r = malloc(p1); }

grow_array(int *p1) {
  *p1 = 1000;
  grow_array_size_needed = *p1;
  xmalloc(grow_array_size_needed);
  grow_array(&page_list_size);
}

expand_string() {
  expand_string_tmp = xmalloc_r;
  output_buffer = expand_string_tmp;
  airac_observe(output_buffer, 0);
}
