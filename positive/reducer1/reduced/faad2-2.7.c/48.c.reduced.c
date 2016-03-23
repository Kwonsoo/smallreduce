char close_audio_file_header[68];
char *close_audio_file_p;
close_audio_file() {
  unsigned tmp;
  close_audio_file_p = close_audio_file_header;
  tmp = close_audio_file_p++;
  airac_observe(tmp, 0);
}
