char close_audio_file_header[68];
char *close_audio_file_p;
close_audio_file() {
  unsigned tmp___9;
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
  tmp___9 = close_audio_file_p;
  airac_observe(tmp___9, 0);
}
