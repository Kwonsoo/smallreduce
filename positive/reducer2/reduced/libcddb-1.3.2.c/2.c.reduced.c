enum __anonenum_cddb_error_t_27 { CDDB_ERR_LAST } do_search_tmp;
static err_str[21];
cddb_error_str(enum __anonenum_cddb_error_t_27 errnum) {
  if (errnum < 0)
    ;
  else if (errnum >= 21)
    ;
  else
    airac_observe(err_str, errnum);
}

cddb_error_stream_print(errnum) {
  cddb_error_str(errnum);
  do_search_tmp = cddb_errno();
  cddb_error_stream_print(do_search_tmp);
}
