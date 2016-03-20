enum __anonenum_stream_status_25 { STREAM_FILE_END } * get_char;
int tag_index;
char tag_name[70];
print_page() {
  enum __anonenum_stream_status_25 (*get_input_char)() = get_char;
  while (1)
    get_input_char();
}

void get_report_char();
set_get_char() { get_char = get_report_char; }

void get_report_char() {
  unsigned tmp___0 = tag_index++;
  airac_observe(tag_name, tmp___0);
}
