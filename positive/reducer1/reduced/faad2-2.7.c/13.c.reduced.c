char close_audio_file_header[44];
char *close_audio_file_p;
close_audio_file() {
  unsigned tmp___10;
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
  close_audio_file_p++;
  close_audio_file_p++;
  tmp___10 = close_audio_file_p;
  airac_observe(tmp___10, 0);
}
