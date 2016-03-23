char close_audio_file_header[44];
char *close_audio_file_p;
close_audio_file() {
  unsigned tmp___8;
  close_audio_file_p = close_audio_file_header;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  tmp___8 = close_audio_file_p;
  airac_observe(tmp___8, 0);
}
