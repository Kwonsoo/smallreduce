int md5_process_block_correct_words[16];
int *md5_process_block_cwp;
md5_process_block() {
  unsigned tmp;
  md5_process_block_cwp = md5_process_block_correct_words;
  tmp = md5_process_block_cwp++;
  airac_observe(tmp, 0);
}
