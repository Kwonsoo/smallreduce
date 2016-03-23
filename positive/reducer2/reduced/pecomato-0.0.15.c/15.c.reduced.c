char iptc_edit_insert_chunks_dataset_header[7];
char *iptc_edit_insert_chunks_ptr;
iptc_edit_insert_chunks() {
  unsigned tmp___10;
  iptc_edit_insert_chunks_ptr = iptc_edit_insert_chunks_dataset_header;
  iptc_edit_insert_chunks_ptr++;
  iptc_edit_insert_chunks_ptr++;
  iptc_edit_insert_chunks_ptr++;
  tmp___10 = iptc_edit_insert_chunks_ptr;
  airac_observe(tmp___10, 0);
}
