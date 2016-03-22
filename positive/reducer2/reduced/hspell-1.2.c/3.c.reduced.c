void *gzb_dopen_tmp, *read_dict_fp;
int read_dict_tmp;
main() { read_dict(); }

read_dict() {
  read_dict_tmp = fopen();
  read_dict_fp = read_dict_tmp = do_read_dict(read_dict_fp);
  gzb_dopen_tmp = malloc(sizeof(int));
  do_read_dict(gzb_dopen_tmp);
}

do_read_dict(p1) {
  int *gzbp = p1;
  airac_observe(gzbp, 0);
}
