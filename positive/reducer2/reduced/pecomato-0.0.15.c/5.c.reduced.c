char iptc_edit_insert_chunks_dataset_header[7];
char *iptc_edit_insert_chunks_ptr;
iptc_edit_insert_chunks() {
  unsigned tmp;
  iptc_edit_insert_chunks_ptr = iptc_edit_insert_chunks_dataset_header;
  tmp = iptc_edit_insert_chunks_ptr++;
  airac_observe(tmp, 0);
}
