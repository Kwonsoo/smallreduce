char close_audio_file_header[44];
char *close_audio_file_p;
close_audio_file() {
  unsigned tmp___1;
  close_audio_file_p = close_audio_file_header;
  close_audio_file_p++;
  close_audio_file_p++;
  tmp___1 = close_audio_file_p;
  airac_observe(tmp___1, 0);
}
