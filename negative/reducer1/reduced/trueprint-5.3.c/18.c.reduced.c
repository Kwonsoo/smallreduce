void *xmalloc_r;
int page_list_size, grow_array_size_needed, output_buffer___0;
grow_array(int *p1) {
  *p1 = 1000;
  grow_array_size_needed = *p1;
  xmalloc_r = malloc(grow_array_size_needed);
  while (1)
    grow_array(&page_list_size);
}

expand_character() {
  output_buffer___0 = xmalloc_r;
  airac_observe(output_buffer___0, 0);
}
