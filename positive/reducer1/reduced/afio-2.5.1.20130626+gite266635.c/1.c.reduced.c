char compress_arg_list[102];
int compress_arg_no = 1;
main() {
  while (1)
    add_arg();
}

add_arg() {
  int tmp;
  if (compress_arg_no < 101)
    tmp = compress_arg_no++;
  airac_observe(compress_arg_list, tmp);
}
