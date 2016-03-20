char current_filename;
long file_number;
void *xmalloc_r;
int file_list_size, files, grow_array_size_needed;
main() {
  while (1) {
    add_file(current_filename, file_number, 1);
    file_number++;
  }
}

xmalloc(s) {
  xmalloc_r = malloc(s);
  return xmalloc_r;
}

grow_array(void *list_ptr_ptr, int *list_size_ptr) {
  *list_size_ptr += 1000;
  grow_array_size_needed = *list_size_ptr;
  *(void **)list_ptr_ptr = xmalloc(grow_array_size_needed);
}

add_file(char *filename, int this_file_number, long this_file_page_number) {
  grow_array(&files, &file_list_size);
  airac_observe(files, this_file_number);
  xmalloc(0);
}
