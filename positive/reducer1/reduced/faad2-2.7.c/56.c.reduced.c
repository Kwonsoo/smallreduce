char close_audio_file_header[68];
char *close_audio_file_p;
close_audio_file() {
  unsigned tmp___7;
  close_audio_file_p = close_audio_file_header;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  close_audio_file_p++;
  tmp___7 = close_audio_file_p;
  airac_observe(tmp___7, 0);
}
