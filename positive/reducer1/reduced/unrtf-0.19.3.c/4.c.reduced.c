long buffer_size;
static input_str;
void *my_malloc_tmp;
char *my_malloc();
my_getchar() {
  buffer_size = 2048;
  my_malloc(buffer_size);
}

word_read() {
  input_str = my_malloc(10);
  my_getchar();
  int str = input_str;
  airac_observe(str, 0);
}

main() { word_read(); }

char *my_malloc(p1) {
  my_malloc_tmp = malloc(p1);
  return my_malloc_tmp;
}
