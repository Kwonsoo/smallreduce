int md5_process_block_correct_words[16];
int *md5_process_block_cwp;
md5_process_block() {
  unsigned tmp___9;
  md5_process_block_cwp = md5_process_block_correct_words;
  md5_process_block_cwp++;
  md5_process_block_cwp++;
  md5_process_block_cwp++;
  md5_process_block_cwp++;
  md5_process_block_cwp++;
  tmp___9 = md5_process_block_cwp;
  airac_observe(tmp___9, 0);
}
