long page_number;
void *xrealloc_r, *xrealloc_v;
int file_list_size, page_list_size, files, pages, grow_array_size_needed;
main() {
  while (1) {
    page_number++;
    page_has_changed(page_number);
  }
}

grow_array(void *list_ptr_ptr, int *list_size_ptr) {
  *list_size_ptr = 1000;
  grow_array_size_needed = *list_size_ptr;
  xrealloc_r = realloc(xrealloc_v, grow_array_size_needed);
  *(void **)list_ptr_ptr = xrealloc_r;
}

page_has_changed(this_page_number) {
  grow_array(&pages, &page_list_size);
  airac_observe(pages, this_page_number);
  grow_array(files, &file_list_size);
}
