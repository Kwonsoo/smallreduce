void *xmalloc_r;
int grow_array_size_needed, output_buffer;
grow_array(p1) {
  grow_array_size_needed = p1;
  xmalloc_r = malloc(grow_array_size_needed);
  grow_array(sizeof(int));
}

expand_string() {
  if (output_buffer == 0)
    output_buffer = xmalloc_r;
  else
    airac_observe(output_buffer, 0);
}
