typedef char gsm_frame[33];
gsm_frame process_decode_s;
char *process_decode_c = process_decode_s;
process_decode() {
  unsigned tmp = process_decode_c++;
  airac_observe(tmp, 0);
}
